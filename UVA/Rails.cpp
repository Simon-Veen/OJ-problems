#include<cstdio>
#include<stack>

using namespace std;
const int MAXN=1e3+10;

int a[MAXN];
stack<int> s;

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int n,t;
    bool ok=1;
    while(scanf("%d",&n)&&n){

        while(scanf("%d",&t)&&t){
            a[1]=t;
            ok=1;
            for(int i=2;i<=n;i++) scanf("%d",&a[i]);
            int cnt=1,ptr=1;
            while(cnt!=n+1){
                if(ptr==a[cnt]){
                    ptr++;
                    cnt++;
                }
                else if(!s.empty()&&a[cnt]==s.top()){
                    cnt++;
                    s.pop();
                }
                else if(ptr==n+1){
                    ok=0;
                    printf("No\n");
                    break;
                }
                else {
                    s.push(ptr);
                    ptr++;
                }
            }
            if(ok)printf("Yes\n");
            while(!s.empty()) s.pop();
        }
        printf("\n");
    }
}
