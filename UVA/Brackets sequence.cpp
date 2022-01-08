#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int INF=1e3;
char a[150];
int fin[150][150];
bool match(char a,char b){
    if(a=='(' && b==')')return true;
    else if(a=='[' && b==']')return true;
    return false;
}
int dfs(int l,int r){
    if(l==r)return 1;
    if(l>r)return 0;
    if(fin[l][r]!=INF) return fin[l][r];

    if(match(a[l],a[r])) fin[l][r]=min(fin[l][r],dfs(l+1,r-1));
    for(int i=l;i<r;i++){
        fin[l][r]=min(fin[l][r],dfs(l,i)+dfs(i+1,r));
    }
    return fin[l][r];
}

void print(int l,int r){
    if(l>r)return;
    if(l==r){
        if(a[l]=='('||a[r]==')')printf("()");
        else printf("[]");
        return;
    }
    int ans=fin[l][r];
    if(match(a[l],a[r]) && ans==fin[l+1][r-1]){
        printf("%c",a[l]);
        print(l+1,r-1);
        printf("%c",a[r]);
        return;
    }
    for(int k=l;k<r;k++){
        if(ans==fin[l][k]+fin[k+1][r]){
            print(l,k);
            print(k+1,r);
            return;
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int t,n,cnt;
    bool ok=0;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--){
        char x;
        cnt=1;
        while(1){
            x=getchar();
            if(x=='\n')break;
            a[cnt++]=x;
        }
        getchar();
        if(ok)putchar('\n');
        ok=1;
        for(int i=0;i<150;i++)
            for(int j=0;j<150;j++){
                if(i!=j)fin[i][j]=INF;
                else fin[i][j]=1;
            }

        if(dfs(1,cnt-1)==0){
            for(int i=1;i<cnt;i++)
                printf("%c",a[i]);
            printf("\n");
        }
        else {
            print(1,cnt-1);
            printf("\n");
        }

    }
}
