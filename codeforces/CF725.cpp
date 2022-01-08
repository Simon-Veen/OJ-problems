#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int _;
    scanf("%d",&_);
    while(_--){
        long long x,y,a,b;
        long long ans=0;
        scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
        if(a==b){
            printf("%lld\n",min(x,y)/a);
        }
        else{
            //only pick up a or b may get an answer
            ans=max(ans,min(x/a,y/b));
            ans=max(ans,min(x/b,y/a));
            //not only pick up a or b but pick a and b may get an answer
            if(a>b)swap(a,b);
            int x0=(y*b-a*x)/(b*b-a*a);
            //notice that x0 is intersection point, but may not get a integer,so we need to search between x0 
            for(long long i=x0-3;i<=x0+3;i++){
                if(i<0)continue;
                long long leftx=x-i*a;
                long long lefty=y-i*b;
                if(leftx<0||lefty<0)continue;
                ans=max(ans,i+min(leftx/b,lefty/a));
            }
            printf("%lld\n",ans);
        }
    }
}
/*
E
#include<cstdio>
#include<map>
#include<iostream>
#include<string>
#include<algorithm>
typedef long long LL;

using namespace std;
string x,c,a,b;
LL count(string k){
    LL cnt=0;
    int len=k.size();
    for(int i=0;i<len;i++){
        if(k[i]=='h'&&i+3<len){
            if(k[i+1]=='a'&& k[i+2]=='h'&& k[i+3]=='a'){
                cnt++;
            }
        }
    }
    return cnt;
}
string pre(string k){
    string nw="";
    int len=k.size();
    for(int i=0;i<min(len,3);i++){
        nw+=k[i];
    }
    return nw;
}
string back(string k){
    string nw="";
    int len=k.size();
    for(int i=len-min(3,len);i<len;i++){
        nw+=k[i];
    }
    return nw;
}
int main()
{
    int _;
    scanf("%d",&_);
    while(_--){
        int n;
        scanf("%d",&n);
        map<string,string> m;
        map<string,LL> mans;
        for(int i=1;i<=n;i++){
            cin>>x>>c;
            if(c[0]==':'&&c[1]=='='){
                cin>>a;
                m[x]=a;
                mans[x]=count(a);
                if(i==n)printf("%lld\n",count(a));
            }
            else{
                string j;
                cin>>a>>j>>b;
                j=back(m[a])+pre(m[b]);
                mans[x]=mans[a]+mans[b]+count(j);
                if(i==n)printf("%lld\n",mans[x]);
                m[x]=pre(m[a])+back(m[b]);
            }
        }
    }
}
/*
#include<cstdio>
using namespace std;
int getprime(int x){
    int cnt=0;
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            cnt++;
            x/=i;
        }
    }
    return cnt+(x>1?1:0);
}
int main()
{
    int a,b,k,cnta,cntb;
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%d%d%d",&a,&b,&k);
        int cnta=getprime(a),cntb=getprime(b);
        if(k==1&&a!=b&&(a%b==0||b%a==0)){
            printf("YES\n");
        }

        else if(1<k&&k<=cnta+cntb) printf("YES\n");
        else printf("NO\n");
    }
}
/*
#include<cstdio>
#include<cstring>
using namespace std;

char a[14],b[14];
int num[10]={1,10,110,1110,11110,111110,1111110,11111110,111111110,1111111110};

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s %s",&a,&b);
        int lena=strlen(a),lenb=strlen(b);
        int ansl=0,ansr=0;
        for(int i=0;i<lena;i++){
            ansl+=num[lena-i-1]*(a[i]-'0');
        }
        for(int i=0;i<lenb;i++){
            ansr+=num[lenb-i-1]*(b[i]-'0');
        }
        if(lenb==lena)printf("%d\n",ansr-ansl);
        else if(lenb>lena)printf("%d\n",ansr-ansl+1);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
    }
}



/*
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2e5+10;
int a[MAXN];
int main()
{
    //freopen("1.txt","r",stdin);

    int t;
    scanf("%d",&t);

    while(t--){
        int n,l,r;
        long long int cnt=0;
        scanf("%d%d%d",&n,&l,&r);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(int i=1;i<n;i++){
            int pl=lower_bound(a+1,a+1+n,l-a[i])-a;
            int pr=upper_bound(a+1,a+1+n,r-a[i])-a;
            if(pl<=i)pl=i+1;
            if(pl<=pr){
                cnt+=pr-pl;
            }
           // printf("%d %d %d\n",cnt,pl,pr);
        }
        printf("%lld\n",cnt);
    }
}
/*
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2e5+10;
int a[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int ave=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ave+=a[i];
        }
        if(ave%n==0){
            ave=ave/n;
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]>ave){
                    cnt++;
                }
            }
            printf("%d\n",cnt);
        }
        else{
            printf("-1\n");
        }

    }

}
/*
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=105;

int a[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int maxx=0,minn=MAXN;
        int mxv,miv;
        for(int i=1;i<=n;i++){
            if(a[i]>maxx){
                maxx=a[i];
                mxv=i;
            }
            if(a[i]<minn){
                minn=a[i];
                miv=i;
            }
        }
        int l=min(miv,mxv);
        int r=max(miv,mxv);
        int ans=min(r,n-l+1);
        ans=min(ans,l+n-r+1);
        printf("%d\n",ans);
    }
}
*/
