#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

string a;
int cnt=0;
bool ans=0;

bool pan(){
    string x,y;
    int len=a.size();
    for(int i=1;i<=len/2;i++){
        for(int j=0;j<len;j++){
            for(int p=j;p<j+i;p++){
                x+=a[p];
            }
            for(int p=j+i;p<j+i+i;p++){
                y+=a[p];
            }
            if(x==y){
                return false;
            }
            x.clear();
            y.clear();
        }
    }
    return true;
}
void dfs(int n,int l){
    if(ans)return;
    if(pan()){
        cnt++;
        if(cnt==n+1){
            ans=1;
            int len=a.size();
            for(int i=0;i<len;i++){
                if(i!=0&&i%4==0&&i%64!=0){
                    printf(" %c",a[i]);
                }
                else if(i!=0&&i%64==0){
                    printf("\n%c",a[i]);
                }
                else printf("%c",a[i]);
            }
            printf("\n%d\n",len);
            return;
        }
    }
    else return;

    for(int i=0;i<l;i++){
        a+=char('A'+i);
        dfs(n,l);
        a.pop_back();
    }
}

int main()
{
    int n,l;
    while(scanf("%d%d",&n,&l)!=EOF&&n&&l){
        ans=0;
        cnt=0;
        a.clear();
        dfs(n,l);
    }
}
