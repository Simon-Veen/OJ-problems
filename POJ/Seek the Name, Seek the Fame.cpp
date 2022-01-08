

#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=4e5+10;
char a[MAXN];
int nxt[MAXN],ans[MAXN];

void getnext(char *k,int len){
    int j=0;
    memset(nxt,0,sizeof(nxt));
    for(int i=1;i<len;i++){
        while(k[j]!=k[i]&&j>0)j=nxt[j-1];
        if(k[j]==k[i])nxt[i]=++j;
    }
}

int main()
{
    while(scanf("%s",a)!=EOF){
        int len=strlen(a);
        getnext(a,len);
        int p=len-1,cnt=1;
        ans[cnt++]=len;
        while(nxt[p]>0){
            ans[cnt++]=nxt[p];
            p=nxt[p-1];
        }
        for(int i=cnt-1;i>=1;i--){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
}
