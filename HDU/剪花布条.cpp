#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e3+10;
char w[MAXN],t[MAXN];
int nxt[MAXN];
void getnext(char *k,int len)
{
    int j=0;
    nxt[0]=nxt[1]=0;
    for(int i=1;i<len;i++){
        while(k[i]!=k[j]&&j>0)j=nxt[j-1];
        if(k[i]==k[j])nxt[i]=++j;
    }
}
int main()
{
    while(scanf("%s",t)){
        int tlen=strlen(t);
        if(tlen==1&&t[0]=='#') break;
        scanf("%s",w);
        int wlen=strlen(w);
        getnext(w,wlen);
        int j=0,cnt=0;
        for(int i=0;i<tlen;i++){
            while(w[j]!=t[i]&&j>0)j=nxt[j-1];
            if(w[j]==t[i])j++;
            if(j==wlen){
                j=0;
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }

}
