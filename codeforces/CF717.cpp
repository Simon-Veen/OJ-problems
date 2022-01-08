
/*
B
#include<cstdio>
#include<cstring>

const int MAXN=2005;
using namespace std;
int a[MAXN][MAXN];
int b[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            sum=0;
            for(int j=i;j<=n;j++){
                if(i==j){
                    a[i][j]=b[i];
                    sum=b[i];
                }
                else{
                    sum=sum^b[j];
                    a[i][j]=sum;
                }
            }
        }
        bool ans=0;
        for(int i=1;i<n;i++){
            if(a[1][i]==a[i+1][n]){
                ans=1;
                break;
            }
            for(int j=i+2;j<=n;j++){
                if(a[1][i]==a[i+1][j-1]&&a[j][n]==a[i+1][j-1]){
                    ans=1;
                    break;
                }

            }
        }
        puts(ans? "YES":"NO");
    }
}

A
#include<cstdio>
const int MAXN=1e3+10;
int a[MAXN];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]); 
        for(int i=1;i<n;i++){
            if(k-a[i]>=0){
                k-=a[i];
                a[n]+=a[i];
                a[i]=0;
            }
            else {
                a[i]-=k;
                a[n]+=k;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}

*/