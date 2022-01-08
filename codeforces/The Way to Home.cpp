#include<cstdio>
#include<algorithm>
using namespace std;

const int INF=1e6;
const int MAXN=150;
char a[MAXN];
int mem[MAXN];
int cnt=0,n,d;

int dfs(int x,int level){
    int sum=INF;
    if(x==n-1)return 0;
    if(mem[x])return mem[x];
    for(int i=1;i<=level;i++){
        if(i+x<n&&a[i+x]=='1'){
            sum=min(sum,dfs(i+x,level)+1);
        }
    }
    mem[x]=sum;
    return mem[x];
}
int main()
{
    scanf("%d%d%s",&n,&d,a);
    if(a[0]!='1'){
        printf("-1\n");
    }
    else{
        int ans=dfs(0,d);
        if(ans<INF)printf("%d\n",dfs(0,d));
        else printf("-1\n");
    }
}
