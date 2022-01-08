#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=2e3+3;
int a[MAXN],f[MAXN][MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)f[i][i]=n*a[i];
    for(int i=2;i<=n;i++){
        for(int l=1;l<=n;l++){
            int r=i+l-1;
            //if(r>n)break;
            f[l][r]=max(f[l+1][r]+a[l]*(n-i+1),f[l][r-1]+a[r]*(n-i+1));
        }
    }
    printf("%d",f[1][n]);
}
