#include<cstdio>
#include<cstring>

struct DAY{
    int cast,from,to;
};

int box[1000005];
int maxn=0,minx=0x7FFFFFFF;
int diff[1000005],need[1000005];
int n,m;
DAY time[1000005];

bool judge(int k)
{
    int sum=0;
    std::memset(diff,0,sizeof(diff));
    for(int i=1;i<=k;i++)
    {
        diff[time[i].from]+=time[i].cast;
        diff[time[i].to+1]-=time[i].cast;
    }
    for(int i=1;i<=n;i++)
    {
        need[i]=diff[i]+need[i-1];
        if(need[i]>box[i])return true;
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&box[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&time[i].cast,&time[i].from,&time[i].to);
        if(time[i].cast>maxn)maxn=time[i].cast;
        if(time[i].cast<minx)minx=time[i].cast;
    }
    int left=1,right=m;
    int mid;
    if(!judge(m))
    {
        printf("0");
        return 0;
    }
    while(left<right)
    {
        mid=(left+right)>>1;
        if(judge(mid))right=mid;
        else left=mid+1;
    }
    printf("-1\n%d",left);
}