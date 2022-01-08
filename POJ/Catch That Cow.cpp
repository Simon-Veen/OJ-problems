#include<cstdio>
#include<queue>
using namespace std;
const int MAXN=3e5+10;
struct node{
    int x,cnt;
};
queue<node> q;
bool vis[MAXN];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    node j;
    j.x=n;j.cnt=0;
    q.push(j);
    vis[j.x]=1;
    while(!q.empty()){
        node w;
        w=q.front();
        q.pop();
        if(w.x==k){
            printf("%d\n",w.cnt);
            break;
        }
        if(w.x-1>=0){
            node v;
            if(!vis[w.x-1]){
                v.x=w.x-1;
                v.cnt=w.cnt+1;
                vis[w.x-1]=1;
                q.push(v);
            }
        }
        if(w.x<k){
            node v;
            if(!vis[w.x+1]){
                v.x=w.x+1;
                v.cnt=w.cnt+1;
                vis[w.x+1]=1;
                q.push(v);
            }
            if(!vis[w.x*2]){
                v.x=w.x*2;
                v.cnt=w.cnt+1;
                vis[w.x*2]=1;
                q.push(v);
            }
        }
    }
}
