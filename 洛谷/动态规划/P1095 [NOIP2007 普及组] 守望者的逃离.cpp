#include<cstdio>
#include<algorithm>
using namespace std;
const int Tmax=3e5+2,Mmax=1e3+2;
int f[Tmax][25];
int s,t,m;
int ans=Tmax,log=0;
bool ok=0;
int dfs(int magic,int time)
{
    if(time==0) return 0;
    if(f[time][magic])return f[time][magic];

    if(magic>=10)
        f[time][magic]=dfs(magic-10,time-1)+60;
    else
        f[time][magic]=max(dfs(magic,time-1)+17,dfs(magic+4,time-1));
    return f[time][magic];
}
int main()
{
    scanf("%d%d%d",&m,&s,&t);
    int e=m/10;m=m%10;
    if(s-e*60<=0)
    {
        int k=s/60;
        if(s%60!=0)k++;
        if(k<=t)printf("Yes\n%d",k);
    }
    else{
        int k=min(e,t);
        for(int i=1;i<=t-k;i++)
            if(dfs(m,i)+k*60>=s)
            {
                printf("Yes\n%d",i+k);
                ok=1;
                break;
            }
        if(!ok&&f[t-k][m]+k*60<=s){
            printf("No\n%d",f[t-k][m]+k*60);
        }
    }
}
