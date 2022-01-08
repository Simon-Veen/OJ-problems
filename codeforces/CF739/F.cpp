#include<bits/stdc++.h>
using namespace std;
int a[15];
bool vis[10];
bool judge(int k,int len){
    int cnt=0;
    for(int i=len-1;i>=0;i--){
        if(vis[a[i]]==0){
            vis[a[i]]=1;
            cnt++;
        }
    }
    memset(vis,0,sizeof(vis));
    if(cnt<=k)return 1;
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long num,cp;
        int k;
        cin>>num>>k;
        cp=num;
        int cnt=0;
        while(cp){
            a[cnt++]=cp%10;
            cp/=10;
        }
        int tot=0;
        while(!judge(k,cnt)){
            for(int i=cnt-1;i>=0;i--){
                if(!vis[a[i]]&&k!=tot-1){
                    vis[a[i]]=1;
                    tot++;
                    if(tot-1==k){
                        a[i]+=1;
                    }
                }
                else if(k==tot-1){
                    a[i]=0;
                }
            }
            for(int j=0;j<cnt;j++){
                if(a[j]>=10){
                    if(j+1==cnt)cnt++;
                    a[j+1]+=a[j]/10;
                    a[j]=a[j]%10;
                }
            }
            memset(vis,0,sizeof(vis));
            tot=0;
        }
        reverse(a,a+cnt);
        for(int i=0;i<cnt;i++){
            cout<<a[i];
        }
        cout<<endl;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
    }
}
