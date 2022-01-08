#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN=2e3+10;
const long long int INF=1e18;
int a[MAXN][MAXN];
struct node{
    int x,y;
    long long int c;
};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool vis[MAXN][MAXN];
queue<node> q;

int main()
{
    int n,m,c;
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    node j;
    j.x=1;j.y=1;j.c=0;
    q.push(j);
    long long no_cost=INF,cost=INF;
    if(a[1][1]>0){
        cost=a[1][1];
    }
    vis[1][1]=1;
    while(!q.empty()){
        node k=q.front();
        q.pop();
        if(k.x==n&&k.y==m&&no_cost>k.c){
            no_cost=k.c;
        }
        int xx,yy;
        for(int i=0;i<4;i++){
            xx=k.x+dx[i];
            yy=k.y+dy[i];
            if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&!vis[xx][yy]&&a[xx][yy]!=-1){
                node ne;
                ne.x=xx;ne.y=yy;
                if(a[xx][yy]>0){
                    ne.c=k.c+c+a[xx][yy];
                    cost=min(cost,ne.c);
                }
                ne.c=k.c+c;
                q.push(ne);
                vis[xx][yy]=1;
            }
        }
    }
    j.x=n;j.y=m;j.c=0;
    q.push(j);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)vis[i][j]=0;
    }
    vis[n][m]=1;
    long long int b_cost=INF;
    if(a[n][m]>0)b_cost=a[n][m];
    while(!q.empty()){
        node k=q.front();
        q.pop();
        int xx,yy;
        for(int i=0;i<4;i++){
            xx=k.x+dx[i];
            yy=k.y+dy[i];
            if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&!vis[xx][yy]&&a[xx][yy]!=-1){
                node ne;
                ne.x=xx;ne.y=yy;
                if(a[xx][yy]>0){
                    ne.c=k.c+c+a[xx][yy];
                    b_cost=min(b_cost,ne.c);
                }
                ne.c=k.c+c;
                q.push(ne);
                vis[xx][yy]=1;
            }
        }
    }
    if(no_cost>b_cost+cost)printf("%lld\n",b_cost+cost);
    else if(no_cost!=INF)printf("%lld\n",no_cost);
    else if(no_cost==INF)printf("-1\n");
}
/*
F2
没搞出来
#include<cstdio>

int main()
{
    int n,t,k;
    scanf("%d%d",&n,&t);
    int cnt=0;
    while(cnt<t){
        scanf("%d",&k);
        int l=1,r=n,mid=(l+r)/2;
        while(l<r){
            printf("? 1 %d\n",mid);
            fflush(stdout);
            int a;
            scanf("%d",&a);
            if(mid-a<k){
                l=mid+1;
                mid=(l+r)/2;
            }
            else {
                r=mid;
                mid=(l+r)/2;
            }
        }
        printf("! %d\n",r);
        cnt++;
    }
}

第一次尝试交互题，挺有意思的


#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n,t,k;
    scanf("%d%d",&n,&t);
    scanf("%d",&k);
    int l=1,r=n,mid=(l+r)/2;
    while(l<r){
        printf("? 1 %d\n",mid);
        fflush(stdout);
        int a;
        scanf("%d",&a);
        if(mid-a<k){
            l=mid+1;
            mid=(l+r)/2;
        }
        else {
            r=mid;
            mid=(l+r)/2;
        }
    }
    printf("! %d\n",r);
}

猜了一下中间的数是最小的（双向奔赴？）后来查一下了是中位数的性质。
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e6+5;
char a[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,maxn=0;
        scanf("%d%s",&n,a);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]=='*')cnt++;
        }
        int ptr;
        if(cnt%2==0){
            int p=0;
            for(int i=0;i<n;i++){
                if(p==cnt/2){
                    ptr=i;
                    break;
                }
                if(a[i]=='*')p++;
            }
        }
        else{
            int p=0;
            for(int i=0;i<n;i++){
                if(a[i]=='*')p++;
                if(p==(cnt+1)/2){
                    ptr=i;
                    break;
                }
            }
        }
        int left=ptr-1,right=ptr+1;
        int t=left;
        long long int sum=0;
        if(a[ptr]!='*'){
            left=ptr;
        }
        while(1){
            if(t<0)break;
            if(a[t]=='*'){
                sum+=(left-t);
                left--;
            }
            t--;
        }
        t=right;
        while(1){
            if(t==n)break;
            if(a[t]=='*'){
                sum+=t-right;
                right++;
            }
            t++;
        }
        printf("%lld\n",sum);
    }
}

/*
    学习如何遍历map，定义一个迭代器
    注意区别unorder_map,它是一个哈希表，由于其通用性速度比手写的差一些


#include<cstdio>
#include<map>
using namespace std;

map<int,long long int> m;
map<int,long long int>::iterator p;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            m[k-i]++;
        }
        long long int ans=0;
        for(p=m.begin();p!=m.end();p++){
            ans+=(p->second*(p->second-1)/2);
        }
        m.clear();
        printf("%lld\n",ans);
    }
}
*/
