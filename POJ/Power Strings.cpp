#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN=1e6+10;
char a[MAXN];
int nxt[MAXN];

int getnext(char *k,int len){
    int j=0;
    memset(nxt,0,sizeof(nxt));
    for(int i=1;i<len;i++){
        while(k[j]!=k[i]&&j>0)j=nxt[j-1];
        if(k[j]=k[i])nxt[i]=++j;
    }
    return len-nxt[len-1];
}
int main()
{
    while(scanf("%s",a)!=EOF){
        if(a[0]=='.')break;
        int len=strlen(a);
        int minlen=getnext(a,len);
        if(len%minlen==0&&len/minlen>1)printf("%d\n",len/minlen);
        else{
            printf("1\n");
        }
    }
}