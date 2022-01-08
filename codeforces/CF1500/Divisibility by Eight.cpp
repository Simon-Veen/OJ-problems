#include<bits/stdc++.h>
using namespace std;
const int N=205;
vector<string> s;
int ans[N][N];
int where;
string rev(string k){
    string mm="";
    int len=k.size()-1;
    for(int i=len;i>=0;i--){
        mm+=k[i];
    }
    return mm;
}
void init()
{
    int cnt=0;
    for(int i=0;i<=200;i++){
        if(i%8==0){
            string z="";
            int cp=i;
            while(cp){
                z+=(cp%10+'0');
                cp/=10;
            }
            if(z.size()==0)s.push_back("0");
            else{
                z=rev(z);
                s.push_back(z);
            }
        }
    }
    int len=s.size();
}

bool getmatch(string a,string b,bool w){
    int la=a.size(),lb=b.size();
    if(!w){
        if(la==3){
            a=a.substr(1);
        }
        else return false;
    }
    la=a.size();
    memset(ans,0,sizeof(ans));
    int loc=0;
    for(int i=0;i<la;i++){
        for(int j=0;j<lb;j++){
            if(a[i]==b[j]){
                if(i&&j)ans[i][j]=ans[i-1][j-1]+1;
                else ans[i][j]=1;
            }
            if(i)ans[i][j]=max(ans[i][j],ans[i-1][j]);
            if(j)ans[i][j]=max(ans[i][j],ans[i][j-1]);
            if(!where&&ans[i][j]==la)where=j;
        }
    }
    if(ans[la-1][lb-1]==la)return true;
    return false;
}
int main()
{
    init();
    string a,ct;
    cin>>a;
    ct=a.substr(1);
    int len=s.size();
    bool ok=0;
    for(int i=0;i<len;i++){
        string p=s[i];
        if(getmatch(p,a,1)){
            cout<<"YES"<<endl<<p<<endl;
            ok=1;
            break;
        }
        if(getmatch(p,ct,0)){
            p=p.substr(1);
            int i,la=a.size();
            for(i=0;i<la&&a[i]!=p[0]&&i<where;i++){
                if((a[i]-'0')%2==1){
                    ok=1;
                    break;
                }
            }
            if(ok){
                cout<<"YES"<<endl<<a[i]+p<<endl;
                break;
            }
        }
    }
    if(!ok)cout<<"NO"<<endl;
}