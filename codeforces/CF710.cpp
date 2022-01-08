/*
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;
const int MAXN=2e5;
char a[MAXN+5];
bool vis[27];
int last[27];
vector<char> v;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",a+1);
        int len=strlen(a+1);
        for(int i=1;i<=len;i++){
            last[a[i]-'a']=i;
        }
        for(int i=1;i<=len;i++){
            if(vis[a[i]-'a'])continue;
            while(v.size()>0&&a[i]>v[v.size()-1]&&last[v[v.size()-1]-'a']>i){
                vis[v[v.size()-1]-'a']=0;
                v.pop_back();
            }
            v.push_back(a[i]);
            vis[a[i]-'a']=1;
        }
        int l=v.size();
        for(int i=0;i<l;i++){
            printf("%c",v[i]);
        }
        printf("\n");
        v.clear();
        for(int i=0;i<27;i++){
            vis[i]=last[i]=0;
        }
        memset(a,0,sizeof(a));
    }
}

*/
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;


const int MAXN=2e5;
struct p{
    int lv,num;
};
p a[MAXN+5];
bool cmp(p x,p y){
    return x.lv<y.lv;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].lv);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].num);
        }
        sort(a+1,a+1+n,cmp);
        int ans=0;
        a[0].lv=1;a[0].num=1;
        for(int i=1;i<=n;i++){
            if(a[i].lv-a[i].num==a[i-1].lv-a[i-1].num){
                if((a[i-1].lv+a[i-1].num)%2==0){
                    ans+=a[i].lv-a[i-1].lv;
                }
            }
            else{
                if((a[i-1].lv+a[i-1].num)%2==0){
                    ans+=(a[i].lv-a[i-1].lv-a[i].num+a[i-1].num)/2;
                }
                else{
                    ans+=(a[i].lv-a[i-1].lv-a[i].num+a[i-1].num+1)/2;
                }
            }
        }
        printf("%d\n",ans);
        memset(a,0,sizeof(a));
    }
}

/*
//E题
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=2e5+10;
int a[MAXN];
int b[MAXN];

bool vis[MAXN];
int fa(int a)
{
    if(vis[a]){
       return b[a]=fa(b[a]);
    }
    else return a;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,cnt=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[a[i]]=a[i]+1;
        }
        int m=0;
        for(int i=1;i<=n;i++){
            if(!vis[a[i]]){
                vis[a[i]]=1;
                printf("%d ",a[i]);
            }
            else {
                if(vis[cnt]){
                    cnt=fa(cnt);
                }
                vis[cnt]=1;
                printf("%d ",cnt++);
            }
        }
        printf("\n");
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)b[i]=i;

        for(int i=1;i<=n;i++){
            if(!vis[a[i]]){
                vis[a[i]]=1;
                printf("%d ",b[a[i]]);
                b[a[i]]=b[a[i]-1];
            }
            else{
                printf("%d ",b[a[i]]);
                vis[b[a[i]]]=1;
                b[a[i]]=b[b[a[i]]-1];
            }
        }
        printf("\n");
        memset(vis,0,sizeof(vis));
    }
    return 0;
}

/*
#include<cstdio>
#include<queue>
#include<map>

using namespace std;
map<int,int> app;
priority_queue<pair<int,int>> q;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int k;
        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            app[k]++;
        }
        for(auto [x,y]:app){
            q.push({y,x});
        }
        int len=n;
        while(q.size()>=2){
            auto [a1,b1]=q.top();
            q.pop();
            auto [a2,b2]=q.top();
            q.pop();
            a1--;
            a2--;
            len-=2;
            if(a1>0){
                q.push({a1,b1});
            }
            if(a2>0){
                q.push({a2,b2});
            }
        }
        app.clear();
        while(!q.empty())q.pop();
        printf("%d\n",len);
    }

}

/*
C
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

char a[25],b[25];
int mem[25][25][25][25];

int dfs(int la,int ra,int lb,int rb){
    if(mem[la][ra][lb][rb])return mem[la][ra][lb][rb];
    if(la>ra||lb>rb)return 0;

    if(ra-la==rb-lb){
        int xa=la,xb=lb;
        bool ans=1;
        while(xa<=ra&&xb<=rb){
            if(a[xa]!=b[xb]){
                ans=0;
                break;
            }
            if(a[xa]==b[xb]){
                xa++;
                xb++;
            }
        }
        if(ans){
            return mem[la][ra][lb][rb]=ra-la+1;
        }
    }
    //����ıȽϿ�����a.substr(la,ra)==b.substr(lb,rb)���ж�

    bool ok=0;
    for(int i=la;i<=ra;i++){
        for(int j=lb;j<=rb;j++){
            if(a[i]==b[j]){
                ok=1;
                break;
            }
        }
        if(ok)break;
    }
    if(!ok)return 0;
    int ans=0;
    ans=dfs(la+1,ra,lb,rb);
    ans=max(ans,dfs(la,ra-1,lb,rb));
    ans=max(ans,dfs(la,ra,lb+1,rb));
    ans=max(ans,dfs(la,ra,lb,rb-1));
    return mem[la][ra][lb][rb]=ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",a+1,b+1);
        int la=strlen(a+1);
        int lb=strlen(b+1);
        int ans=dfs(1,la,1,lb);
        printf("%d\n",la-ans+lb-ans);
        memset(mem,0,sizeof(mem));
    }
}

B
#include<cstdio>

const int MAXN=80;
char a[MAXN];

int main()
{

    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",a+1);
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]=='*'){
                a[i]='X';
                cnt++;
                break;
            }
        }
        int bac=0;
        for(int i=n;i>=1;i--){
            if(a[i]=='*'){
                a[i]='X';
                bac=i;
                cnt++;
                break;
            }
        }
        for(int i=1;i<bac;i++){
            if(a[i]=='X'){
                bool ok=0;
                for(int j=i+1;j<=i+k;j++){
                    if(a[j]=='X'){
                        ok=1;
                        break;
                    }
                }
                if(!ok){
                    for(int j=i+k;j>=i+1;j--){
                        if(a[j]=='*'){
                            a[j]='X';
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }

}


A��
#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long int n,m,x;
        cin>>n>>m>>x;
        long long int xx,yy;
        xx=x/n;
        yy=x%n;
        if(x%n==0){
            xx--;
            yy=n;
        }
        cout<<(xx+1)+(yy-1)*m<<endl;
    }
}
*/
