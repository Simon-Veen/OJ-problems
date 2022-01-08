#include<cstdio>
#include<algorithm>

using namespace std;
const int MAXN=100+10;
int box[MAXN][MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&box[i][j]);
               box[i][j]=box[i-1][j]+box[i][j-1]+box[i][j]-box[i-1][j-1];
        }
    }
    int ans=0;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-1;j++){
            for(int k=i+1;k<=n;k++){
                for(int p=j+1;p<=n;p++){
                    ans=max(ans,box[k][p]-box[i-1][p]-box[k][j-1]+box[i-1][j-1]);//这里是二维的前缀和
                }
            }
        }
    }
    printf("%d",ans);
}
