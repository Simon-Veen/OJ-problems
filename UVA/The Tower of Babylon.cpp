#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;
struct Blocks{
    int x,y,z;
};
int n;
vector<Blocks> box;
queue<int> q;
bool graph[105][105];
int v[105],in[105];
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int x,y,z,cnt=1;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&x,&y,&z);
            Blocks a;
            a.x=x;a.y=y;a.z=z;
            box.push_back(a);
            a.x=y;a.y=z;a.z=x;
            box.push_back(a);
            a.x=z;a.y=x;a.z=y;
            box.push_back(a);
        }
        for(int i=0;i<box.size();i++){
            for(int j=0;j<box.size();j++){
                if(i==j)continue;
                if(box[i].x>box[j].x&&box[i].y>box[j].y){
                        graph[i][j]=1;
                        in[j]++;
                }
                else if(box[i].x>box[j].y&&box[i].y>box[j].x){
                        graph[i][j]=1;
                        in[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<box.size();i++){

            if(in[i]==0){
                q.push(i);
                v[i]=box[i].z;
                ans=max(ans,v[i]);
            }
        }

        while(!q.empty()){
            int head=q.front();
            q.pop();

            for(int i=0;i<box.size();i++){
                if(graph[head][i]){
                    in[i]--;
                    v[i]=max(v[i],v[head]+box[i].z);
                    ans=max(ans,v[i]);
                    if(in[i]==0)q.push(i);
                }
            }
        }
        printf("Case %d: maximum height = %d\n",cnt++,ans);
        box.clear();
        memset(graph,0,sizeof(graph));
        memset(v,0,sizeof(v));
        memset(in,0,sizeof(in));
    }
}
