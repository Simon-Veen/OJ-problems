#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN=2e5+10;
long long int n;
struct people{
    long long int s;
    long long int id;
    int ord;
}t[MAXN];
bool cmp(people a,people b){
    return a.id<b.id;
}
bool cmp1(people a,people b){
    return a.ord<b.ord;
}
int main()
{
    long long int k;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&t[i].id);
        t[i].ord=i;
    }
    sort(t+1,t+1+n,cmp);
    long long int tot=k/n;
    k-=tot*n;
    for(int i=1;i<=n;i++){
        t[i].s+=tot+(i<=k?1:0);
    }
    sort(t+1,t+1+n,cmp1);
    for(long long int i=1;i<=n;i++){
        printf("%lld\n",t[i].s);
    }
}



/*
#include<cstdio>

const int MAXN=14;
int x[MAXN];

int main()
{
    int a,cnt=1,now=1;
    scanf("%d",&a);
    for(int i=1;i*now<=a;i++){
        now*=i;
        x[cnt++]=now;
    }
    int left=0,t=0;
    for(int j=cnt-1;j>=1;j--){
        t=a/x[j];
        if(t==0)continue;
        left+=a/x[j];
        a-=(a/x[j])*x[j];
        if(a==0)break;
    }
    printf("%d\n",left);
}

/*
#include<cstdio>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a<=b&&b<=6*a)printf("Yes\n");
    else printf("No\n");
}

*/
