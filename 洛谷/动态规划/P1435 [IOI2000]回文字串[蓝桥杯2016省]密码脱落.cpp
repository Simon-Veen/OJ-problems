#include<cstdio>
#include<algorithm>
#include<cstring>


using namespace std;
char box[1004];
char p[1004];
int ans[1004][1004];
int main()
{
    scanf("%s",box+1);
    int len=strlen(box+1),cnt=1;
    for(int i=len;i>=1;i--)
        p[cnt++]=box[i];
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            if(box[i]==p[j])ans[i][j]=ans[i-1][j-1]+1;
            else ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
        }
    }
    printf("%d",len-ans[len][len]);
}
