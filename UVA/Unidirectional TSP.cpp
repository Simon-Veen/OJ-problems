#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

vector<int> v;
int mp[15][105];
int mem[15][105];
int n,m;

int dfs(int x,int y){
    if(y==m+1){
        return 0;
    }
    if(mem[x][y])return mem[x][y];

    if(x+1>n){
        mem[x][y]=dfs(1,y+1)+mp[x][y];
    }
    else mem[x][y]=dfs(x+1,y+1)+mp[x][y];
    if(x-1<1){
        mem[x][y]=min(mem[x][y],dfs(n,y+1)+mp[x][y]);
    }
    else mem[x][y]=min(mem[x][y],dfs(x-1,y+1)+mp[x][y]);
    mem[x][y]=min(mem[x][y],dfs(x,y+1)+mp[x][y]);
    return mem[x][y];

}
bool print(int x,int y){
    if(x+1>n&&mem[1][y+1]+mp[x][y]==mem[x][y]){
        v.push_back(1);
        if(y+1==m){
            return true;
        }
        if(print(1,y+1)){
            return true;
        }
        v.pop_back();
    }
    else if(x-1>=1&&mem[x-1][y+1]+mp[x][y]==mem[x][y]){
        v.push_back(x-1);
        if(y+1==m){
            return true;
        }
        if(print(x-1,y+1)){
            return true;
        }
        v.pop_back();
    }
    else if(mem[x][y+1]+mp[x][y]==mem[x][y]){
        v.push_back(x);
        if(y+1==m){
            return true;
        }
        if(print(x,y+1)){
            return true;
        }
        v.pop_back();
    }
    else if(x+1<=n&&mem[x+1][y+1]+mp[x][y]==mem[x][y]){
        v.push_back(x+1);
        if(y+1==m){
            return true;
        }
        if(print(x+1,y+1)){
            return true;
        }
        v.pop_back();
    }
    else if(x-1<1&&mem[n][y+1]+mp[x][y]==mem[x][y]){
        v.push_back(n);
        if(y+1==m){
            return true;
        }
        if(print(n,y+1)){
            return true;
        }
        v.pop_back();
    }
    return false;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&mp[i][j]);
            }
        }
        int ans=1e6;
        int xx=0;
        for(int i=1;i<=n;i++){
            int k=dfs(i,1);
            if(k<ans){
                ans=k;
                xx=i;
            }
        }
        v.push_back(xx);
        print(xx,1);
        for(int i=0;i<v.size()-1;i++){
            printf("%d ",v[i]);
        }
        printf("%d",v[v.size()-1]);
        printf("\n%d\n",ans);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                mem[i][j]=0;
                mp[i][j]=0;
            }
        }
        v.clear();
    }
}
