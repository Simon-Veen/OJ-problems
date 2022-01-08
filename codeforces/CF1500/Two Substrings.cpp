#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
char a[N];
int ans[N][2];

//ans[i][0] £º
int main()
{
    scanf("%s",a);
    int len=strlen(a);
    bool ok=0;
    for(int i=0;i<len;i++){
        if(a[i-1]=='A'&&a[i]=='B'){
            ans[i][0]=1;
            ans[i][1]=ans[i-1][1];
            if(ans[i-2][1]){
                printf("YES\n");
                ok=1;
                break;
            }
        }
        else if(a[i-1]=='B'&&a[i]=='A'){
            ans[i][1]=1;
            ans[i][0]=ans[i-1][0];
            if(ans[i-2][0]){
                printf("YES\n");
                ok=1;
                break;
            }
        }
        else{
            ans[i][0]=ans[i-1][0];
            ans[i][1]=ans[i-1][1];
        }
    }
    if(!ok)printf("NO\n");
}
