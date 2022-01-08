#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=10000+10;
int in[MAXN],map[105][105];
vector<int> v[MAXN];
int ans[MAXN]={0},INF=1;
queue<int> q;
int main()
{
    int n,m,cnt=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&map[i][j]);
            ans[cnt]=1;
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){              //¹¹½¨ÁÚ½Ó¾ØÕó
        for(int j=1;j<=m;j++){
            if(j-1>=1&&map[i][j]<map[i][j-1]){
                v[(i-1)*m+j].push_back((i-1)*m+(j-1));
                in[(i-1)*m+(j-1)]++;
            }
            if(i-1>=1&&map[i][j]<map[i-1][j]){
                v[(i-1)*m+j].push_back((i-1-1)*m+j);
                in[(i-1-1)*m+j]++;
            }
            if(i+1<=n&&map[i][j]<map[i+1][j]){
                in[i*m+j]++;
                v[(i-1)*m+j].push_back(i*m+j);
            }
            if(j+1<=m&&map[i][j]<map[i][j+1]){
                in[(i-1)*m+j+1]++;
                v[(i-1)*m+j].push_back((i-1)*m+j+1);
            }
        }
    }
    for(int i=1;i<cnt;i++)
        if(in[i]==0)
            q.push(i);
    while(!q.empty()){
        int head=q.front();
        INF=max(INF,ans[head]);
        q.pop();
        for(int i=0;i<v[head].size();i++){
            in[v[head][i]]--;
            ans[v[head][i]]=max(ans[v[head][i]],ans[head]+1);
            if(in[v[head][i]]==0)q.push(v[head][i]);
        }
    }
    printf("%d",INF);
}
