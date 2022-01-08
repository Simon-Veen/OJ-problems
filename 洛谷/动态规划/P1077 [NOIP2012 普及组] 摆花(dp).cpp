#include<cstdio>
#include<algorithm>
using namespace std;


int ans[105][105],a[105];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int k;
    for(int i=0;i<=a[1];i++){
        ans[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=m;j>=0;j--){
            k=0;
            for(int p=0;p<=a[i];p++){
                if(j-p>=0) k=(k+ans[i-1][j-p])%1000007;
            }
            ans[i][j]=k;
        }
    }
    printf("%d",ans[n][m]);
}
