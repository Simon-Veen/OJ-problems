#include<cstdio>
struct obj{
    int c,val;
    bool vis;
};
obj pan[1005];
int cast[1005],num[1005],val[1005];
int ans[1005];
int max(int a,int b)
{
    return a>b? a:b;
}
int main()
{
    int m,n,d=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&cast[i],&val[i],&num[i]);
        d=max(d,num[i]);
    }
    for(int p=1;p<=d;p++){
        for(int i=1;i<=n;i++){
            if(num[i]==p)
            for(int j=m;j>=cast[i];j--){
                    ans[j]=max(ans[j],ans[j-cast[i]]+val[i]);
            }
        }

    }
    /*
    for(int p=1;p<=d;p++)
    {
        for(int i=m;i>=0;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(num[j]==p&&i-cast[j]>=0)
                ans[i]=max(ans[i],ans[i-cast[j]]+val[j]);
            }
        }
    }
    */
    printf("%d",ans[m]);
}
