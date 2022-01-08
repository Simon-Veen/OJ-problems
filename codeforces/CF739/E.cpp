#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int cnt[30],tot[30];
bool vis[30];
char a[N];
string ans,prefix;
int judge(){
    int len=ans.size(),sum=0;
    for(int i=0;i<len;i++){
        int ptr=ans[i]-'a';
        if(tot[ptr]%(i+1)!=0)return -1;
        sum+=tot[ptr]/(i+1);
    }
    return sum;
}
int main()
{
    int _;
    scanf("%d",&_);
    while(_--){
        scanf("%s",a);
        int len=strlen(a);
        for(int i=0;i<len;i++){
            tot[a[i]-'a']++;
        }
        vis[a[len-1]-'a']=1;
        ans=a[len-1];
        char cur=a[len-1];
        for(int i=len-2;i>=0;i--){
            int ptr=a[i]-'a';
            if(vis[ptr]||a[i]==cur)continue;
            else{
                ans+=a[i];
                cur=a[i];
                vis[cur-'a']=1;
            }
        }
        reverse(ans.begin(),ans.end());
        int num=judge();
        if(num==-1){
            cout<<"-1"<<endl;
        }
        else{
            for(int j=0;j<num;j++){
                prefix+=a[j];
            }
            bool ok=1;
            int la=ans.size(),lp=prefix.size(),ptr=num;
            string e=prefix,x="";
            for(int i=0;i<la;i++){
                for(int j=0;j<lp;j++){
                    if(e[j]!=ans[i])x+=e[j];
                }
                int p1=0,lx=x.size();
                if(x=="")break;
                while(1){
                    if(a[ptr]==x[p1]){
                        ptr++;
                        p1++;
                    }
                    if(p1==lx&&ptr<=len)break;
                    if(a[ptr]!=x[p1]){
                        ok=0;
                        break;
                    }
                }
                if(!ok)break;
                e=x;x="";lp=x.size();
            }
            if(ok)cout<<prefix<<" "<<ans<<endl;
            else cout<<"-1"<<endl;
        }
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        memset(tot,0,sizeof(tot));
        ans="";prefix="";
    }
}
