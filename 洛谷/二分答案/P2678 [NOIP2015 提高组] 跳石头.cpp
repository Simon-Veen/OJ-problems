#include<cstdio>

int n,m,l;
int box[50005];

bool judge(int k)
{
    int val=0,x=0;
    int cast=0;
    for(int i=1;i<=m;i++)
    {
        if(box[i]-val>=k)
            val=box[i];

        else cast++;
    }
    if(n-val>=k&&cast<=l) return true;

    return false;
}

int main()
{
    scanf("%d%d%d",&n,&m,&l);
    for(int i=1;i<=m;i++)
        scanf("%d",&box[i]);

    int left=0,right=n;
    int mid;
    while(left<right)
    {
        mid=(left+right+1)/2;
        if(judge(mid))left=mid;
        else right=mid-1;
    }
    printf("%d",left);
}
