#include<cstdio>
#include<cstring>
using namespace std;


const int MAXN=5e4+10;

int a[MAXN];
struct tree{
    int l,r;
    int sum;
}t[MAXN*4];

char s[6];


void build(int p,int l,int r){

    t[p].l=l;t[p].r=r;
    if(l==r){
        t[p].sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].sum=t[p*2].sum+t[p*2+1].sum;
}
void change(int p,int num,int v){
    if(t[p].l==t[p].r&&t[p].l==num){
        t[p].sum+=v;
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(num<=mid){
        change(p*2,num,v);
        t[p].sum=t[p*2].sum+t[p*2+1].sum;
    }
    else if(num>mid){
        change(p*2+1,num,v);
        t[p].sum=t[p*2].sum+t[p*2+1].sum;
    }
}
int ask(int p,int l,int r){

    if(l<=t[p].l&&t[p].r<=r){
        return t[p].sum;
    }
    int mid=(t[p].l+t[p].r)/2;
    int sum=0;
    if(l<=mid){
        sum+=ask(p*2,l,r);
    }
    if(r>mid){
        sum+=ask(p*2+1,l,r);
    }
    return sum;
}
int main()
{
    int tt,cnt=1;
    scanf("%d",&tt);
    while(tt--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        build(1,1,n);
        printf("Case %d:\n",cnt++);
        while(scanf("%s",s)!=EOF){
            if(s[0]=='E')break;
            else if(s[0]=='Q'){
                int f,t;
                scanf("%d%d",&f,&t);
                printf("%d\n",ask(1,f,t));
            }
            else if(s[0]=='A'){
                int f,num;
                scanf("%d%d",&f,&num);
                change(1,f,num);
            }
            else if(s[0]=='S'){
                int f,num;
                scanf("%d%d",&f,&num);
                change(1,f,-num);
            }
        }
        memset(t,0,sizeof(t));
    }

}
