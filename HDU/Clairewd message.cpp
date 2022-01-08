#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN=1e5+10;
char a[MAXN],zi[30],b[MAXN],de[30];
int nxt[MAXN],z[MAXN];

void getnxt(char *k,int len){
    nxt[0]=len;
    int now=0;
    while(now+1<len&&k[now]==k[now+1])now++;
    nxt[1]=now;
    int ps=1;
    for(int i=2;i<len;i++){
        if(i+nxt[i-ps]<nxt[ps]+ps)nxt[i]=nxt[i-ps];
        else{
            int j=max(0,nxt[ps]+ps-i);
            while(j+i<len&&k[j]==k[j+i])j++;
            nxt[i]=j;
            ps=i;
        }
    }
}
void exkmp(char *x,char *y){
    int j=0;
    int xlen=strlen(x),ylen=strlen(y);
    while(j<min(xlen,ylen)&&x[j]==y[j])j++;
    z[0]=j;
    int ps=0;
    for(int i=1;i<xlen;i++){
        if(i+nxt[i-ps]<z[ps]+ps)z[i]=nxt[i-ps];
        else{
            int j=max(0,z[ps]+ps-i);
            while(j+i<xlen&&j<ylen&&x[j+i]==y[j])j++;
            z[i]=j;
            ps=i;
        }
    }
}
int main()
{
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%s %s",zi,a);
        int len=strlen(a);
        for(int i=0;i<26;i++){
            de[zi[i]-'a']=i+'a';
        }
        for(int i=0;i<len;i++){
            b[i]=de[a[i]-'a'];
        }
        getnxt(b,len);
        exkmp(a,b);
        int i;
        for(i=(len+1)/2;i<len;i++){
            if(z[i]+i==len){
                break;
            }
        }
        a[i]='\0';b[i]='\0';  //'\0'是字符数组的结束标志
        printf("%s%s\n",a,b);

    }
}