#include<cstdio>
#include<algorithm>

using namespace std;
const int MAXN=60;
int box[MAXN][MAXN];
int ans[MAXN][MAXN][MAXN][MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&box[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                for(int p=j+1;p<=m;p++){
                    int aa=max(ans[i-1][j][k-1][p],ans[i-1][j][k][p-1]);
                    int bb=max(ans[i][j-1][k-1][p],ans[i][j-1][k][p-1]);
                    ans[i][j][k][p]=max(aa,bb)+box[i][j]+box[k][p];
                }

            }
        }
    }
    printf("%d",ans[n][m-1][n-1][m]);

}
