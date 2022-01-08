//扩展KMP做法
#include<cstring>
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=1e5+10;
char a[MAXN],b[MAXN];

int nex[MAXN],ex[MAXN];
void getz(char *s,int len){
    int n=len;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && nex[i - l] < r - i + 1) {
        nex[i] = nex[i - l];
        } else {
        nex[i] = max(0, r - i + 1);
        while (i + nex[i] < n && s[nex[i]] == s[i + nex[i]]) ++nex[i];
        }
        if (i + nex[i] - 1 > r) l = i, r = i + nex[i] - 1;
    }
}

int main()
{
    while(scanf("%s",a)!=EOF){
        int i=strlen(a);
        scanf("%s",b);
        a[i]=' ';
        strcat(a,b);
        getz(a,strlen(a));
        int ans=-1,tag=-1,len=strlen(a);
        for(i;i<len;i++){
            if(i+nex[i]==len){
                ans=nex[i];
                tag=i;
                break;
            }
        }
        if(ans==-1){
            printf("0\n");
        }
        else{
            for(int i=tag;i<tag+ans;i++){
                printf("%c",a[i]);
            }
            printf(" %d\n",ans);
        }
        memset(a,0,sizeof(a));
    }
}


/*

KMP做法


#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>

using namespace std;
const int MAXN=1e5+10;
string a,b,c;
int nxt[MAXN];

void getnext(string k,int len){
    int j=0;
    memset(nxt,0,sizeof(nxt));
    for(int i=1;i<len;i++){
        while(k[i]!=k[j]&&j>0)j=nxt[j-1];
        if(k[i]==k[j])nxt[i]=++j;
    }
}

int main(){
    while(cin>>b>>c){
        a=b+" "+c;
        int len=a.size();
        getnext(a,len);
        int maxlen=nxt[len-1];
        if(maxlen==0)printf("0\n");
        else{
            for(int i=len-maxlen;i<len;i++){
                printf("%c",a[i]);
            }
            printf(" %d\n",maxlen);
        }
    }
}
*/
