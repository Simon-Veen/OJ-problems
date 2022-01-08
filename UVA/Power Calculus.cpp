#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e3;
int a[MAXN];
bool ok=0;
bool IDA(int now,int len,int level,int deep,int goal){
    if(now==goal&&level<=deep){
        ok=1;
        return true;
    }
    if(ok){
        return true;
    }
    if(level>deep)return false;
    if(now*pow(2,deep-level)<goal)return false;
    for(int i=len-1;i>=0;i--){
        a[len]=now+a[i];
        IDA(now+a[i],len+1,level+1,deep,goal);
        a[len]=now-a[i];
        IDA(now-a[i],len+1,level+1,deep,goal);
    }
    /*
    有一种贪心做法是：如果当前now还没有到goal就一直加，只有超过时才减。
    这种做法是错误的，由于此题数据较小，必须直接暴力才能得到正确答案
    if(now<goal){
        for(int i=len-1;i>=0;i--){
            a[len]=now+a[i];
            IDA(now+a[i],len+1,level+1,deep,goal);
        }
    }
    else if(now>goal){
        for(int i=len-1;i>=0;i--){
            if(now-a[i]>=1){
                a[len]=now-a[i];
                IDA(now-a[i],len+1,level+1,deep,goal);
            }
        }
    }
    */
    if(!ok)return false;
    else return true;
}
int main()
{
    int t;
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    while(scanf("%d",&t)&&t){
        int deep=0;
        ok=0;
        a[0]=1;
        while(!IDA(1,1,0,deep,t)){
            deep++;
        }

        printf("%d\n",deep);
    }
}
/*
错误的贪心做法，有些情况不是最优的。
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
int low_ans,high_ans;
int low_dfs(int goal){
    int d=0,cur=0;
    while(1){
        cur=log2(goal);
        d+=1;
        if(pow(2,cur)==goal)break;
        goal=goal-pow(2,cur);
    }
    return d;
}
int high_dfs(int goal){
    int d=0,cur=0;
    while(1){
        cur=log2(goal);
        d+=1;
        if(pow(2,cur)==goal)break;
        goal=goal-pow(2,cur);
    }
    return d;
}
int main()
{
    int t;
    while(scanf("%d",&t)&&t){
        int d=log2(t);
        if(pow(2,d)==t){
            printf("%d\n",d);
            continue;
        }
        else {
            int u=d+1;
            int ans=min(d+low_dfs(t-pow(2,d)),u+high_dfs(pow(2,u)-t));
            printf("%d\n",ans);
        }
    }
}
*/
