#include<cstdio>

const int MAXN=1e3+10;
char a[MAXN];


int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        scanf("%s",a);
        int cnt=0,zero=0;
        for(int i=0;i<n;i++){
            if(a[i]!=a[n-i-1]&&i!=n-i-1){
                a[i]=a[n-i-1]=1;
                cnt++;
            }
            else if(a[i]=='0'){
                zero++;
            }
        }
        if(cnt>=3){
            printf("ALICE\n");
        }
        else if(cnt==2){
            if(zero==0||zero%2==1){
                printf("ALICE\n");
            }
            else if(zero%2==0){
                printf("DRAW\n");
            }
        }
        else if(cnt==1){
            if(zero==0){
                printf("ALICE\n");
            }
            else if(zero%2==1)printf("DRAW\n");
            else if(zero%2==0)printf("BOB\n");
        }
        else if(cnt==0){
            if(zero==0)printf("DRAW\n");
            else if(zero%2==1&&zero!=1)printf("ALICE\n");
            else if(zero%2==0||zero==1)printf("BOB\n");
        }
    }
}

/*
B1

#include<cstdio>



const int MAXN=1e3+10;
char a[MAXN];
int main()
{

    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        scanf("%s",a);
        int num=0;
        for(int i=0;i<n;i++){
            if(a[i]=='0')num++;
        }
        if(num==0)printf("DRAW\n");
        else if(num%2==1&&num!=1)printf("ALICE\n");
        else if(num%2==0||num==1)printf("BOB\n");
    }
}




C题，区间扩展问题

#include<cstdio>
#include<map>
using namespace std;
const int MAXN=1e5+10;
map<int,long long int> m;
int a[MAXN];
long long int b[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=m[a[i]]+=i;
        }
        long long int sum=0;
        for(int i=1;i<=n;i++){
            sum+=(n-i+1)*(b[i]-i);
        }
        printf("%lld\n",sum);
        m.clear();
    }
}


不知道取对数为什么会错，本地测试8得7，上交测试得到3
无语

#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    //freopen("2.txt","w",stdout);
    int n;
    scanf("%d",&n);
    while(n--){
        int k;
        scanf("%d",&k);
        int p=log10(k)/log10(2);
       // printf("%d\n",p);
        int j=pow(2,p);
        printf("%d\n",j-1);
    }
    return 0;
}
)

*/
