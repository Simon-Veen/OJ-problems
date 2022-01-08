#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN=1e5;
vector<int> v[MAXN+5];
int n,t;
int dfs(int d){
    if(v[d].size()==0)return 1;
    vector<int> ans;
    for(int i=0;i<v[d].size();i++){
        ans.push_back(dfs(v[d][i]));
    }
    sort(ans.begin(),ans.end());
    int len=(v[d].size()*t-1)/100+1;
    int sum=0;
    for(int i=0;i<len;i++){
        sum+=ans[i];
    }
    return sum;
}
int main()
{
    while(scanf("%d%d",&n,&t)!=EOF&&n&&t){
        int a;
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            v[a].push_back(i);
        }
        printf("%d\n",dfs(0));
        for(int i=0;i<=n;i++) v[i].clear();
    }
}