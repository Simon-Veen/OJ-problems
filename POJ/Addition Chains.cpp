#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1e3;
int a[MAXN];
bool ok=0;
bool IDA(int now,int lv,int deep,int goal){

    if(now>goal||lv>deep)return false;
    if(now*pow(2,deep-lv)<goal)return false;
    if(now==goal&&lv<=deep){
        for(int i=1;i<lv;i++)printf("%d ",a[i]);
        printf("%d\n",a[lv]);
        ok=1;
        return true;
    }
    if(ok)return true;
    for(int i=lv;i>=1;i--){
        a[lv+1]=now+a[i];
        IDA(a[lv+1],lv+1,deep,goal);
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)&&n){
        int deep=log2(n);
        if(pow(2,deep)!=n)deep+=1;
        ok=0;
        a[1]=1;
        while(1){
            if(IDA(1,1,deep,n)){
                break;
            }
            deep++;
        }
    }
}
