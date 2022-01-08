#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e6+10,MM=1e4+10;
char w[MM],t[MAXN];
int nxt[MM];
void getnext(char *k,int len){
    int j=0;
    memset(nxt,0,sizeof(nxt));
    for(int i=1;i<len;i++){
        while(k[i]!=k[j]&&j>0)j=nxt[j-1];
        if(k[i]==k[j])nxt[i]=++j;
    }
}
int main()
{
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%s",w);
        scanf("%s",t);
        int wlen=strlen(w),tlen=strlen(t);
        getnext(w,wlen);
        int j=0;
        long long cnt=0;
        for(int i=0;i<tlen;i++){
            while(w[j]!=t[i]&&j>0)j=nxt[j-1];
            if(w[j]==t[i])j++;
            if(j==wlen){
                cnt++;
                j=nxt[j-1];
            }
        }
        printf("%lld\n",cnt);
    }
}