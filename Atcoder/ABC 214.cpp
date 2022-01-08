#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
pair<int,int> a[N];
int main()
{
    int _;
    cin>>_;
    while(_--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
        sort(a+1,a+1+n);
        a[n+1].first=2e9;
        priority_queue<int,vector<int>,greater<int>> q;
        int x=0;
        bool ok=1;
        for(int i=1;i<=n&&ok;i++){
            if(x<a[i].first)x=a[i].first;
            q.push(a[i].second);
            while(i<n&&a[i+1].first==a[i].first){
                q.push(a[i+1].second);
                i++;
            }
            while(!q.empty()&&x<a[i+1].first){
                if(q.top()>=x)x++;
                else{
                    ok=0;break;
                }
                q.pop();
            }
        }
        if(ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

/*
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct edge{
    int f,t,c;
    bool operator < (const edge& p){
        return c<p.c;
    }
}e[N];
int f[N],cnt[N];

int dsu_father(int u){
    if(f[u]!=u)return f[u]=dsu_father(f[u]);
    else return u;
}
void dsu_merge(int u,int v){
    f[v]=u;
    cnt[u]+=cnt[v];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1,f,t,c;i<n;i++){
        scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].c);
    }
    for(int i=1;i<=n;i++){
        f[i]=i;
        cnt[i]=1;
    }
    sort(e+1,e+n);
    long long ans=0;
    for(int i=1;i<n;i++){
        int fa=dsu_father(e[i].f);
        int fb=dsu_father(e[i].t);
        ans+=(long long)cnt[fa]*cnt[fb]*e[i].c;
        dsu_merge(fa,fb);
    }
    printf("%lld\n",ans);

}

/*

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long s[N],t[N];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&s[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&t[i]);
    }
    t[1]=min(t[n]+s[n],t[1]);
    for(int i=2;i<=n;i++){
        t[i]=min(t[i],t[i-1]+s[i-1]);
    }
    t[1]=min(t[n]+s[n],t[1]);
    for(int i=2;i<=n;i++){
        t[i]=min(t[i],t[i-1]+s[i-1]);
    }

    for(int i=1;i<=n;i++){
        printf("%lld\n",t[i]);
    }
}


/*

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s,t;
    scanf("%d%d",&s,&t);
    long long ans=0;
    for(int i=0;i<=s;i++){
        for(int j=0;j<=s;j++){
            for(int p=0;p<=s;p++){
                if(i+j+p<=s&&i*j*p<=t){
                    ans++;
                }
            }
        }
    }
    printf("%lld\n",ans);
}


/*
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    scanf("%d",&n);

    int ans=0;
    if(1<=n&&n<=125)ans=4;

    else if(126<=n&&n<=211)ans=6;

    else if(212<=n&&n<=214)ans=8;

    printf("%d\n",ans);

}
*/
