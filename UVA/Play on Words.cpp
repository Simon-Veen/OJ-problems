#include<cstdio>
#include<cstring>

using namespace std;


const int MAXN=1e3+3;
char a[MAXN];
int f[30],io[30];
bool have[30];
int father(int a){
    return a==f[a]? a:f[a]=father(f[a]);
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<26;i++)f[i]=i;
        memset(io,0,sizeof(io));
        memset(have,0,sizeof(have));
        for(int i=1;i<=n;i++){
            scanf("%s",a);
            int ft=a[0]-'a';
            int len=strlen(a)-1;
            int r=a[len]-'a';

            //除了起点和终点外其他字母的a[i]=0;
            have[ft]=true;
            have[r]=true;
            io[ft]--;   //
            io[r]++;
            f[father(ft)]=father(r);
        }
        int num=0,out=0,in=0;
        for(int i=0;i<26;i++){
            if(have[i]){
                num++;
                if(io[i]==1)in++;
                if(io[i]==-1)out++;
            }
        }
        int sum=0;
        for(int i=0;i<26;i++){
            if(have[i]&&f[i]==i)sum++;
        }
        if(sum==1&&(num==0||(num==2&&in==1&&out==1)))printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
}
