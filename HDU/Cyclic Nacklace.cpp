#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e5+10;

char a[MAXN];
int nxt[MAXN];
void getnext(char *k,int len)
{
    int j=0;
    memset(nxt,0,sizeof(nxt));
    for(int i=1;i<len;i++){
        while(k[j]!=k[i]&&j>0)j=nxt[j-1];
        if(k[j]==k[i])nxt[i]=++j;
    }
}
int main()
{
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%s",a);
        int len=strlen(a);
        getnext(a,len);
        int big=len-nxt[len-1];
        if(big!=len&&len%big==0)printf("0\n");
        else printf("%d\n",big-len%big);
    }
}