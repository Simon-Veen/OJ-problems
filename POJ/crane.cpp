/*
mdzz 加号的优先级高于左移，如果同时出现，则应该p<<1|1表示*2+1；
*/


#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
const int MAXN=1e4+10;
const double pai=3.1415926535897932384626;
double a[MAXN];
struct tree{
    int l,r;
    double x,y;
    int lazy;
}t[MAXN*4];
int pre[MAXN];
int n,m;
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    t[p].lazy=0;
    if(l==r){
        t[p].x=0;
        t[p].y=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    t[p].y=t[p<<1].y+t[p<<1|1].y;
}
void rotate(int p,int v){
    double ag=(double)v*pai/180.0;
    double x=t[p].x*cos(ag)-t[p].y*sin(ag);
    double y=t[p].x*sin(ag)+t[p].y*cos(ag);
    t[p].x=x;
    t[p].y=y;
}
void pushdown(int p){
    if(t[p].lazy!=0){
        int c=t[p].lazy;
        rotate(p<<1,c);
        rotate(p<<1|1,c);
        t[p<<1].lazy+=c;t[p<<1|1].lazy+=c;
        t[p].lazy=0;
    }
}
void change(int p,int l,int r,int c){
    if(l<=t[p].l&&t[p].r<=r){
        t[p].lazy+=c;
        rotate(p,c);
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)>>1;
    if(l<=mid)change(p<<1,l,r,c);
    if(r>mid)change(p<<1|1,l,r,c);
    t[p].x=t[p<<1].x+t[p<<1|1].x;
    t[p].y=t[p<<1].y+t[p<<1|1].y;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%lf",&a[i]);
        }
        build(1,1,n);
        int s,c;
        for(int i=1;i<=n;i++)pre[i]=180;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&s,&c);
            change(1,s+1,n,c-pre[s]);
            printf("%.2lf %.2lf\n",t[1].x,t[1].y);
            pre[s]=c;
        }
        printf("\n");
        memset(t,0,sizeof(t));
        memset(pre,0,sizeof(pre));
    }
}