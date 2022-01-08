#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN=45;

int box[MAXN][MAXN];
int mem[MAXN][MAXN][MAXN][MAXN];
int t;

int dfs(int i,int j,int k,int p,int a[])
{
    if(mem[i][j][k][p])return mem[i][j][k][p];
    int i_ans=0,j_ans=0,k_ans=0,p_ans=0;
    bool ok=0;
    for(int i=0;i<5;i++){
        if(a[i]==0){
            ok=1;
            break;
        }
    }
    if(!ok)return 0;
    if(i+1<=t){
            int v,pt=-1;
            for(int u=0;u<5;u++){
                if(a[u]==box[1][i+1]){
                    i_ans=1;
                    v=a[u];
                    pt=u;
                    break;
                }
            }
            if(pt!=-1){
                a[pt]=0;
                i_ans+=dfs(i+1,j,k,p,a);
                a[pt]=v;
            }
            else{
                for(int u=0;u<5;u++){
                    if(a[u]==0){
                        a[u]=box[1][i+1];
                        pt=u;
                        break;
                    }
                }
                if(pt!=-1){
                    i_ans=dfs(i+1,j,k,p,a);
                    a[pt]=0;
                }
            }
    }
    if(j+1<=t){
            int v,pt=-1;
            for(int u=0;u<5;u++){
                if(a[u]==box[2][j+1]){
                    j_ans=1;
                    v=a[u];
                    pt=u;
                    break;
                }
            }
            if(pt!=-1){
                a[pt]=0;
                j_ans+=dfs(i,j+1,k,p,a);
                a[pt]=v;
            }
            else{
                for(int u=0;u<5;u++){
                    if(a[u]==0){
                        a[u]=box[2][j+1];
                        pt=u;
                        break;
                    }
                }
                if(pt!=-1){
                    j_ans=dfs(i,j+1,k,p,a);
                    a[pt]=0;
                }
            }
    }
    if(k+1<=t){
            int v,pt=-1;
            for(int u=0;u<5;u++){
                if(a[u]==box[3][k+1]){
                    k_ans=1;
                    v=a[u];
                    pt=u;
                    break;
                }
            }
            if(pt!=-1){
                a[pt]=0;
                k_ans+=dfs(i,j,k+1,p,a);
                a[pt]=v;
            }
            else{
                for(int u=0;u<5;u++){
                    if(a[u]==0){
                        a[u]=box[3][k+1];
                        pt=u;
                        break;
                    }
                }
                if(pt!=-1){
                    k_ans=dfs(i,j,k+1,p,a);
                    a[pt]=0;
                }
            }
    }
    if(p+1<=t){
            int v,pt=-1;
            for(int u=0;u<5;u++){
                if(a[u]==box[4][p+1]){
                    p_ans=1;
                    v=a[u];
                    pt=u;
                    break;
                }
            }
            if(pt!=-1){
                a[pt]=0;
                p_ans+=dfs(i,j,k,p+1,a);
                a[pt]=v;
            }
            else{
                for(int u=0;u<5;u++){
                    if(a[u]==0){
                        a[u]=box[4][p+1];
                        pt=u;
                        break;
                    }
                }
                if(pt!=-1){
                    p_ans=dfs(i,j,k,p+1,a);
                    a[pt]=0;
                }
            }
    }
    mem[i][j][k][p]=max(i_ans,j_ans);
    mem[i][j][k][p]=max(k_ans,mem[i][j][k][p]);
    mem[i][j][k][p]=max(p_ans,mem[i][j][k][p]);
    return mem[i][j][k][p];
}
int main()
{
    while(scanf("%d",&t)!=EOF&&t){

        for(int i=1;i<=t;i++){
            for(int j=1;j<=4;j++){
                scanf("%d",&box[j][i]);
            }
        }
        int a[5]={0};
        printf("%d\n",dfs(0,0,0,0,a));
        memset(mem,0,sizeof(mem));
    }
}
