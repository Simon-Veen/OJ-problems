#include<cstdio>

struct people{
    int win,lose,use;
};
people box[1005];
int max(int a,int b)
{
    return a>b? a:b;
}
int ans[1005];
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&box[i].lose,&box[i].win,&box[i].use);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=x;j>=box[i].use;j--)
        {
            if(j-box[i].use>=0)
                ans[j]=max(ans[j-box[i].use]+box[i].win,ans[j]+box[i].lose);
        }
        for(int j=box[i].use-1;j>=0;j--)
            ans[j]+=box[i].lose;
    }
    printf("%lld",ans[x]*5);
}
