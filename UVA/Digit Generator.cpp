#include<cstdio>
#include<cstring>
#define maxn 100005
int ans[maxn];

int main()
{
    int t,n;
    memset(ans,0,sizeof(ans));
    for(int m=1;m<maxn;m++)
    {
        int x=m,y=m;
        while(x>0){y+=x%10;x/=10;}
        if(ans[y]==0 || m<ans[y])ans[y]=m;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
}
