#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<int> v;
vector<int> a;
vector<int> z;
int t;
map<int,int> kk;
bool dfs(int tar,int goal){
    if(tar>goal){
        return false;
    }
    int sum=tar;
    for(int i=0;i<t;i++){
        if(!v[i]){
            sum+=a[i];
        }
    }
    if(sum<goal)return false;
    if(tar==goal){
        bool as=1;
        for(int i=0;i<t;i++){
            if(!v[i]){
                as=0;
            }
        }
        if(as)return true;
        else if(dfs(0,goal))return true;
    }
    map<int,int> gg;
    if(tar<goal){
        for(int i=0;i<t;i++){
            if(!v[i]){
                if(a[i]+tar<=goal&&!gg[a[i]]){
                    v[i]=1;
                    if(dfs(a[i]+tar,goal))return true;
                    gg[a[i]]=1;
                    v[i]=0;
                }
            }
        }
    }
    return false;
}
int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    while(~scanf("%d",&t)&&t){
        int k,s=0,minx=0;
        for(int i=1;i<=t;i++){
            scanf("%d",&k);
            s+=k;
            minx=max(minx,k);
            a.push_back(k);
            v.push_back(0);
        }
        for(int i=1;i<=s;i++){
            if(s%i==0&&i>=minx){
                z.push_back(i);
            }
        }
        int lez=z.size();
        for(int i=0;i<lez;i++){
            if(dfs(0,z[i])){
                printf("%d\n",z[i]);
                break;
            }
        }
        v.clear();
        a.clear();
        z.clear();
    }
}
