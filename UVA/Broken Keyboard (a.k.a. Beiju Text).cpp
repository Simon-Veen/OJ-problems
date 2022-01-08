#include<cstdio>
#include<cstring>

using namespace std;
const int MAXN=1e5+10;
char a[MAXN];
int next[MAXN];

int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    while(scanf("%s",a+1)!=EOF){
        memset(next,0,sizeof(next));
        int len=strlen(a+1);
        int cur=0,rear=0;
        bool ok=1;
        for(int i=1;i<=len;i++){
            if(a[i]!='['&&a[i]!=']'){
                next[i]=next[cur];
                next[cur]=i;
                cur=i;
                if(ok)rear=i;
            }
            else if(a[i]=='['){
                cur=0;
                if(rear!=0)ok=0;
            }
            else if(a[i]==']'){
                cur=rear;
                ok=1;
            }
        }
        int i=0;
        while(next[i]){
            printf("%c",a[next[i]]);
            i=next[i];
        }
        printf("\n");
    }
}
