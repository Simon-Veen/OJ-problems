#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e7;
int d[MAXN+5];
int ans[MAXN+5];
void solve(){

    for(int i=1;i<=MAXN;i++){
        for(int j=1;j*i<=MAXN;j++){
            d[i*j]+=j;
        }
        ans[i]=MAXN;
    }
    for(int i=1;i<=MAXN;i++){
        if(d[i]>MAXN)continue;
        ans[d[i]]=min(ans[d[i]],i);
    }
}
int main()
{
    solve();
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(ans[n]==MAXN)printf("-1\n");
        else printf("%d\n",ans[n]);
    }
}
/*
#include<cstdio>

const int MAXN=1e7+10;
int d[MAXN];
const int MAN=45732192+10;
int f[MAN];
int m=0;
void solve(){
    for(int i=1;i<=10000000;i++){
        for(int j=1;j*i<=10000000;j++){
            d[i*j]+=j;
            if(j==1)f[d[i]]=i;
        }
    }
}
int main()
{
    solve();
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(f[n]!=0)printf("%d\n",f[n]);
        else printf("-1\n");
    }
}

/*
F 记忆化搜索或者dp都可以
#include<cstdio>
#include<algorithm>
using namespace std;


const int MAXN=2e5+10;

int a[MAXN],b[MAXN];
int mem[MAXN];
int n,c;

int dfs(int lv,int sum){

    int w=(c-sum)/a[lv];
    if(w*a[lv]<(c-sum))w++;
    if(lv!=n){
        int edu=(b[lv]-sum)/a[lv];
        if(edu*a[lv]<(b[lv]-sum))edu++;
        return mem[lv]=min(w,dfs(lv+1,(sum+edu*a[lv])-b[lv])+edu+1);
    }
    else return mem[lv]=w;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&c);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<n;i++)scanf("%d",&b[i]);
        printf("%d\n",dfs(1,0));
    }
}


E 暴力递归加剪枝

#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=505;
bool vis[MAXN];
int ans[MAXN];
int n;
bool dfs(int beg,int f,int r,int now,int sum){
    if(f==r+1&&now==sum){
        int p=beg;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                ans[beg]=i;
                beg++;
            }
        }
        return true;
    }
    if(now>=sum&&f<=r)return false;
    int cnt=r-f+1,k=n,s=0,c=0;
    while(c<cnt){
        if(!vis[k]){
            s+=k;
            c++;
        }
        k--;
    }
    if(now+s<sum)return false;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(dfs(beg,f+1,r,now+i,sum))return true;
            vis[i]=0;
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r,s;
        scanf("%d%d%d%d",&n,&l,&r,&s);
        if(!dfs(l,l,r,0,s))printf("-1\n");
        else{
            for(int i=1;i<=n;i++){
                if(ans[i]==0){
                    for(int j=1;j<=n;j++){
                        if(!vis[j]){
                            ans[i]=j;
                            vis[j]=1;
                            break;
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++){
                printf("%d ",ans[i]);
            }
            printf("\n");
        }
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
    }
}



D题，还是要注意不要漏了情况，还有就是做题的时候多手算，有便于找到规律

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int MAXN=2e5+10;
long long int b[MAXN];
int main()
{
    int _;
    scanf("%d",&_);
    while(_--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n+2;i++){
            scanf("%lld",&b[i]);
        }
        sort(b+1,b+1+n+2);
        long long int sum=0;
        for(int i=1;i<=n+1;i++){
            sum+=b[i];
        }
        int p=0;
        for(int i=1;i<=n+1;i++){
            if(sum-b[i]==b[n+2]){
                p=i;
                break;
            }
        }
        if(!p&&sum-b[n+1]==b[n+1])p=n+1;
        if(p){
            for(int i=1;i<=n+1;i++){
                if(i==p)continue;
                printf("%lld ",b[i]);
            }
            printf("\n");
        }
        else printf("-1\n");
    }

}



C题注意要特判已经是回文串的情况


#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=2e5+10;
char z[MAXN];
int main()
{
    //freopen("1.txt","w",stdout);
    int t;
    bool ans=1;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        scanf("%s",z+1);
        int len=strlen(z+1);
        if(a+b!=len){
            printf("-1\n");
            continue;
        }
        int la=0,lb=0;
        for(int i=1;i<=len;i++){
            if(z[i]==z[len-i+1]){
                if(z[i]=='0')la++;
                if(z[i]=='1')lb++;
            }
        }
        if(la==a&&lb==b&&la+lb==len){
            for(int i=1;i<=len;i++){
                printf("%c",z[i]);
            }
            printf("\n");
            memset(z,0,sizeof(z));
            continue;
        }
        ans=1;
        for(int i=1;i<=len;i++){
            if(z[i]!='?'&&z[len-i+1]!='?'&&z[i]!=z[len-i+1]){
                ans=0;
                break;
            }
            if(z[i]=='1'&&z[len-i+1]=='?'){
                z[len-i+1]='1';
            }
            if(z[i]=='0'&&z[len-i+1]=='?'){
                z[len-i+1]='0';
            }
        }
        int cnt_a=0,cnt_b=0,cnt=0;
        for(int i=1;i<=len;i++){
            if(z[i]=='1')cnt_b++;
            if(z[i]=='0')cnt_a++;
            if(z[i]=='?')cnt++;
        }
        if(cnt_b>b||cnt_a>a)ans=0;
        a=a-cnt_a;
        b=b-cnt_b;
        if(a+b!=cnt) ans=0;
        if(cnt%2==0&&a%2==1&&b%2==1){
            ans=0;
        }
        if(!ans){
            printf("-1\n");
            continue;
        }
        if(z[len/2+1]=='?'&&cnt%2==1){
            if(a%2==1){
                z[len/2+1]='0';
                a--;
            }
            else if(b%2==1){
                z[len/2+1]='1';
                b--;
            }
        }
        for(int i=1;i<=len;i++){
            if(z[i]=='?'){
                if(a>0){
                    z[i]='0';
                    a--;
                    if(a>0&&z[len-i+1]=='?'){
                        z[len-i+1]='0';
                        a--;
                    }
                    continue;
                }
                if(b>0){
                    z[i]='1';
                    b--;
                    if(b>0&&z[len-i+1]=='?'){
                        z[len-i+1]='1';
                        b--;
                    }
                    continue;
                }
            }
        }
        for(int i=1;i<=len;i++){
            printf("%c",z[i]);
        }
        printf("\n");
        memset(z,0,sizeof(z));
    }
}




B
#include<cstdio>
#include<cstring>

using namespace std;


char a[404][404];
struct point{
    int x,y;
};

int main()
{
    //freopen("1.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char k;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("\n%c",&k);
                a[i][j]=k;
            }
        }
        point b,c;
        b.x=b.y=0;
        c.x=c.y=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(b.x==0&&a[i][j]=='*'){
                    b.x=i;b.y=j;
                }
                else if(c.x==0&&a[i][j]=='*'){
                    c.x=i;c.y=j;
                }
            }
        }
        if(b.x==c.x){
            if(b.x-1>=1){
                a[b.x-1][b.y]='*';
                a[c.x-1][c.y]='*';
            }
            else if(b.x+1<=n){
                a[b.x+1][b.y]='*';
                a[c.x+1][c.y]='*';
            }
        }
        else if(b.y==c.y){
            if(b.y-1>=1){
                a[b.x][b.y-1]='*';
                a[c.x][c.y-1]='*';
            }
            else if(c.y+1<=n){
                a[b.x][b.y+1]='*';
                a[c.x][c.y+1]='*';
            }
        }
        else if(b.x!=c.x&&b.y!=c.y){
            a[b.x][c.y]='*';
            a[c.x][b.y]='*';
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
    }
}
*/
