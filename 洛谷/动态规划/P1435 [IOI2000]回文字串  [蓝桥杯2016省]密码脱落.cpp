#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;
const int MAXN=1e5+3;
int a[MAXN],b[MAXN];
map<int,int> box;
int f[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        box[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        if(box[b[i]])b[i]=box[b[i]];
    }
    f[1]=b[1];
    int len=1;
    for(int i=2;i<=n;i++){
        if(b[i]>f[len])
            f[++len]=b[i];
        else{
            int x=upper_bound(f+1,f+1+len,b[i])-f;
            f[x]=b[i];
        }
    }
    printf("%d",len);
}

/*
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=1e5+3;
int a[MAXN],f[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        f[i]=1;
    }
    N*logN
    for(int i=1;i<=n;i++){
        int x=upper_bound(a+1,a+n+1,a[i])-a;
        f[x]=max(f[x],f[i]+1);
    }
    printf("%d",f[n]);
    //N^2
    for(int i=2;i<=n;i++){

        for(int j=1;j<i;j++){
            if(a[i]>a[j])f[i]=max(f[i],f[j]+1);
        }
    }
}
*/
/*
#include<cstdio>
#include<algorithm>

using namespace std;
const int MAXN=1e5+3;
int a[MAXN],b[MAXN];
int ans[MAXN][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j])
                ans[i][j]=ans[i-1][j-1]+1;
            else{
                ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
            }
        }
    }
    printf("%d",ans[n][n]);
}
*/
/*
#include<cstdio>
#include<algorithm>
const int MAXN=1e5+3;
int a[MAXN],b[MAXN];
int ans[MAXN][MAXN];
int dfs(int n,int m)
{
    if(n<0||m<0)return 0;
    if(ans[n][m])return ans[n][m];

    if(a[n]==b[m]){
        ans[n][m]=dfs(n-1,m-1)+1;
    }
    else{
        ans[n][m]=std::max(dfs(n-1,m),dfs(n,m-1));
    }
    return ans[n][m];
}


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)scanf("%d",&b[i]);
    printf("%d",dfs(n-1,n-1));

}
*/
