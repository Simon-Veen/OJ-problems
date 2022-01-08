#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char zf[100];
bool p[100];
void clr(int len)
{
    for(int i=0;i<len;i++)p[i]=0;
}
bool pan(int len)
{
    for(int i=0;i<len;i++)if(!p[i])return 0;
    return 1;
}
int main()
{
    int n,pt=0,cnt=1;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",zf);
        pt=0;
        cnt=1;
        clr(strlen(zf));
        while(true)
        {
            if(pt+cnt==strlen(zf))
            {
                if(!pan(strlen(zf))||strlen(zf)%cnt!=0)
                {
                    printf("%d\n",strlen(zf));
                    if(n)printf("\n");
                }
                else
                {
                    printf("%d\n",cnt);
                    if(n)printf("\n");
                }
                break;
            }
            else if(zf[pt]==zf[pt+cnt]){p[pt]=1;p[pt+cnt]=1;pt++;continue;}
            else if(zf[pt]!=zf[pt+cnt]){pt=0;cnt++;clr(strlen(zf));}
        }
    }
}

