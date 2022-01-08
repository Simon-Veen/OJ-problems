#include <iostream>
#include <cstdio>
using namespace std;
long long int F[40010];
long long int INF=192600817;

int main()
{
    //freopen("1.txt","w",stdout);
    F[0]=1,F[1]=1;
    for(int i=2;i<40010;i++)
    {
        F[i]=(F[i-1]%INF+F[i-2]%INF)%INF;
    }
    int a,b,c,d;
    int n;
    for(int i=1;i<40010;i++)
    {
       F[i]=(F[i-1]%INF+(F[i]%INF)*(F[i]%INF)%INF)%INF;// F[i]=(F[i-1]+(F[i]%INF*F[i]%INF)%INF)%INF;
    }
    //printf("%lld %lld\n",F[40002],F[40003]);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            long long int ans=0;
            if(a*4+b>=c*4+d)
            {
                if(F[a*4+b]-F[c*4+d-1]>=0) printf("%lld\n",F[a*4+b]-F[c*4+d-1]);
                else printf("%lld\n",F[a*4+b]-F[c*4+d-1]+INF);
            }
            else
            {
                if(F[c*4+d]-F[a*4+b-1]>=0)printf("%lld\n",F[c*4+d]-F[a*4+b-1]);
                else printf("%lld\n",F[c*4+d]-F[a*4+b-1]+INF);
            }
        }
    }
}
