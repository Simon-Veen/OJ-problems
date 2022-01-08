#include<cstdio>
int pro()
{
    char a;
    int cnt=0,ans=0;
    while(true)
    {
        a=getchar();
        if(a=='\n')break;
        if(a=='O')ans+=++cnt;
        else cnt=0;
    }
    return ans;
}
int main()
{
    int op=0,n;
    char kg;
    scanf("%d",&n);
    kg=getchar();
    for(int i=0;i<n;i++)
        printf("%d\n",pro());
}
