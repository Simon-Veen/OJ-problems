#include<cstdio>
#include<algorithm>
#include<cstring>
#incl
using namespace std;
const int MAXN=5e3+10;
struct Section{
    int l,r;
    int num;
};
Section a[MAXN],b[MAXN];
struct Point{
    int x,y;
};
bool vis[MAXN];
Point ans[MAXN];
bool cmp(Section i,Section j){
    if(i.r==j.r)return i.l<j.l;
    return i.r<j.r;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n){
        for(int i=1;i<=n;i++){
            scanf("%d%d%d%d",&a[i].l,&b[i].l,&a[i].r,&b[i].r);
            a[i].num=i;
            b[i].num=i;
        }
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n,cmp);
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        bool ok;
        for(int i=1;i<=n;i++){
            ok=0;
            for(int j=a[i].l;j<=a[i].r;j++){
                if(!vis[j]){
                    vis[j]=1;
                    ans[a[i].num].x=j;
                    ok=1;
                    break;
                }
            }
            if(!ok){
                break;
            }
        }
        if(!ok){
            printf("IMPOSSIBLE\n");
            continue;
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            ok=0;
            for(int j=b[i].l;j<=b[i].r;j++){
                if(!vis[j]){
                    ans[b[i].num].y=j;
                    vis[j]=1;
                    ok=1;
                    break;
                }
            }
            if(!ok)break;
        }
        if(!ok)printf("IMPOSSIBLE\n");
        else{
            for(int i=1;i<=n;i++){
                printf("%d %d\n",ans[i].x,ans[i].y);
            }
        }
    }
}
