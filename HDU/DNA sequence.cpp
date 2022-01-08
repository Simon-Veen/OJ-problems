#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
char box[10][10];
bool vis[10][10];
int n,len[10];
char h[4]={'A','C','G','T'};
bool IDA(int now,int d,int pos[]){
    int MAXN=0;
    for(int i=0;i<n;i++){
        MAXN=max(MAXN,len[i]-pos[i]);
    }
    if(now-1+MAXN>d)return false;
    if(now==d+1&&MAXN==0)return true;
    int temp[10];
    for(int i=0;i<4;i++){
        for(int j=0;j<n;j++){
            if(box[j][pos[j]]==h[i]){
                temp[j]=pos[j]+1;
            }
            else temp[j]=pos[j];
        }
        if(IDA(now+1,d,temp))return true;
    }
    return false;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int deep=0;
        for(int i=0;i<n;i++){
            scanf("%s",box[i]);
            len[i]=(int)strlen(box[i]);
            deep=max(deep,len[i]);
        }
        int pos[10];
        memset(pos,0,sizeof(pos));
        while(1){
            if(IDA(1,deep,pos)){
                printf("%d\n",deep);
                break;
            }
            deep++;
        }
    }
}
