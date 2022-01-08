#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1e5+3;
int Y_ord[MAXN],Y_rear[MAXN];
int H_ord[MAXN],H_rear[MAXN];
int YH_ord[MAXN],YH_rear[MAXN];
int a[MAXN];

int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(Y_ord,0,sizeof(Y_ord));
        memset(Y_rear,0,sizeof(Y_rear));
        memset(H_ord,0,sizeof(H_ord));
        memset(H_rear,0,sizeof(H_rear));
        memset(YH_ord,0,sizeof(YH_ord));
        memset(YH_rear,0,sizeof(YH_rear));

        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(i==1){
                Y_ord[1]=a[1];
                H_ord[1]=a[1];
                YH_ord[1]=a[1];
            }
            else{
                Y_ord[i]=Y_ord[i-1]&a[i];
                H_ord[i]=H_ord[i-1]|a[i];
                YH_ord[i]=YH_ord[i-1]^a[i];
            }
        }
        Y_rear[n]=a[n];
        H_rear[n]=a[n];
        YH_rear[n]=a[n];
        for(int i=n-1;i>=1;i--){
            Y_rear[i]=Y_rear[i+1]&a[i];
            H_rear[i]=H_rear[i+1]|a[i];
            YH_rear[i]=YH_rear[i+1]^a[i];
        }
        int w;
        for(int i=1;i<=q;i++){
            scanf("%d",&w);
            if(w==1){
                printf("%d ",Y_rear[2]);
                printf("%d ",H_rear[2]);
                printf("%d\n",YH_rear[2]);
            }
            else if(w==n){
                printf("%d ",Y_ord[n-1]);
                printf("%d ",H_ord[n-1]);
                printf("%d\n",YH_ord[n-1]);
            }
            else{
            printf("%d ",Y_ord[w-1]&Y_rear[w+1]);
            printf("%d ",H_ord[w-1]|H_rear[w+1]);
            printf("%d\n",YH_ord[w-1]^YH_rear[w+1]);
            }
        }
    }
}
