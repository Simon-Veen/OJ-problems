
/*
C
贪心+优先队列

#include<cstdio>
#include<queue>
using namespace std;
const int MAXN=2e5+10;
int a[MAXN];
priority_queue<int,vector<int>,greater<int> > q;

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    long long int sum=0;
    int len=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=0){
            sum+=a[i];
            len++;
        }
        else{
            if(!q.empty()){
                if(a[i]+sum>=0){
                    sum+=a[i];
                    q.push(a[i]);
                    len++;
                }
                else{
                    int small=q.top();
                    if(small<a[i]){
                        q.pop();
                        sum-=small;
                        sum+=a[i];
                        q.push(a[i]);
                    }
                }
            }
            else{
                if(a[i]+sum>=0){
                    q.push(a[i]);
                    sum+=a[i];
                    len++;
                }
            }
        }
    }
    printf("%d",len);
}

/*
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int MAXN=2e3+10;
struct node{
    long long int sum;
    int p;
};
map<node,int> m;
int a[MAXN];
int sum[MAXN][2];
int ans[MAXN][2];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sum[1][1]=a[1];
    ans[1][1]=1;
    for(int i=2;i<=n;i++){
        if(sum[i-1][0]+a[i]>=0){
            ans[i][1]=max(ans[i][1],ans[i-1][0]+1);
            sum[i][1]=sum[i-1][0]+a[i];
        }
        if(sum[i-1][0]>=0){
            ans[i][0]=max(ans[i][0],ans[i-1][0]);
            sum[i][0]=sum[i-1][0];
        }
        if(sum[i-1][1]+a[i]>=0){
            if(ans[i-1][1]+1>ans[i][1]){
                ans[i][1]=ans[i-1][1]+1;
                sum[i][1]=sum[i-1][1]+a[i];
            }
        }
        if(sum[i-1][1]>=0){
            if(ans[i][0]<ans[i-1][1]){
                ans[i][0]=ans[i-1][1];
                sum[i][0]=sum[i-1][1];
            }
        }
    }
    printf("%d\n",max(ans[n][0],ans[n][1]));
}
/*
#include<cstdio>
#include<cstring>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        if(n<111){
            if(n%11==0){
                puts("YES");
            }
            else puts("NO");
        }
        else{
            int b=n%11;
            if(n-b*111>=0){
                if((n-b*111)%11==0){
                    puts("YES");
                }
                else puts("NO");
            }
            else puts("NO");
        }
    }
}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXN=100;
int a[MAXN];
int b[MAXN];
bool vis[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+2*n);
        int cnt=2*n;
        for(int i=1;i<=2*n;i+=2){
            b[i]=a[cnt--];
        }
        for(int i=2;i<=2*n;i+=2){
            b[i]=a[cnt--];
        }
        for(int i=1;i<=2*n;i++){
            printf("%d ",b[i]);
        }
        printf("\n");
        memset(b,0,sizeof(b));

    }

}
*/
