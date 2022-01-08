#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e6+10,MM=1e4+10;
int a[MAXN],b[MM],next[MM];

void getNext(int *k,int len)
{
    int j=0;
    memset(next,0,sizeof(next));
    for(int i=1;i<len;i++){
        while(k[j]!=k[i]&&j>0)j=next[j-1];
        if(k[j]==k[i])j++;
        next[i]=j;
    }
}
int main()
{
    int _;
    scanf("%d",&_);
    while(_--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int j=0;j<m;j++)scanf("%d",&b[j]);
        getNext(b,m);
        int j=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(a[i]==b[j]){
                if(j==m-1){
                    ans=i;
                    break;
                }
                else j++;
            }
            else{
                while(a[i]!=b[j]&&j>0){
                    j=next[j-1];
                }
                if(a[i]==b[j])j++;
            }
        }
        if(ans!=-1)printf("%d\n",ans+2-m);
        else printf("-1\n");
    }

}