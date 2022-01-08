#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=2e5+10;
char a[MAXN];
int nxt[MAXN];

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
        int n;
        scanf("%d",&n);
        scanf("%s",a);
        getnext(a,n);
        int ans=n%10007;
        for(int i=0;i<n;i++){
            if(nxt[i]>0){
                int j=i;
                while(nxt[j]>0){
                    j=nxt[j-1];
                    ans=(ans+1)%10007;
                }                
            }
        }
        printf("%d\n",ans);
    }
}