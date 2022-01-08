#include<cstdio>
#include<algorithm>

using namespace std;

struct EDGE{
    int from,to,cast;

};
bool cmp(EDGE a,EDGE b)
{
    return a.cast>b.cast;
}
int f[40005];
EDGE e[100005];
int father(int a)
{
    return a==f[a]? a:f[a]=father(f[a]);
}
bool check(int a,int b)
{
    a=father(a);
    b=father(b);
    if(a==b)return true;
    return false;
}
void add(int a,int b)
{
    a=father(a);
    b=father(b);
    f[a]=b;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].cast);
    for(int i=1;i<=n;i++) f[i]=i;
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m+1;i++)
    {
        if(check(e[i].from,e[i].to))
        {
            printf("%d",e[i].cast);
            break;
        }
        else
        {
            if(!f[e[i].from+n])
                f[e[i].from+n]=e[i].to;
            else
                add(f[e[i].from+n],e[i].to);
            if(!f[e[i].to+n])
                f[e[i].to+n]=e[i].from;
            else
                add(f[e[i].to+n],e[i].from);
        }
    }
}
