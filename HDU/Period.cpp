#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e6+10;
char a[MAXN];
int nxt[MAXN];
void getnext(char *k,int len){
    int j=0;
    memset(nxt,0,sizeof(nxt));
    for(int i=1;i<len;i++){
        while(k[i]!=k[j]&&j>0)j=nxt[j-1];
        if(k[i]==k[j]){
            nxt[i]=++j;
        }
    }
}
int main()
{
    int len,cnt=1;
    while(scanf("%d",&len)&&len!=0){
        scanf("%s",a);
        getnext(a,len);
        printf("Test case #%d\n",cnt++);
        for(int i=1;i<len;i++){
            if((i+1)%(i-nxt[i]+1)==0&&(i+1)/(i-nxt[i]+1)>1){
                printf("%d %d\n",i+1,(i+1)/(i-nxt[i]+1));
            }
        }
        printf("\n");
    }
}