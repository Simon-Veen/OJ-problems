/*
2
1054
6656

3
4





#include<bits/stdc++.h>
using namespace std;
const long long INF=1e17;
vector<string> s;
int ans[20][20];
int getmatch(string x,string y){
    memset(ans,0,sizeof(ans));
    int lx=x.size(),ly=y.size();
    int del=0;
    int i=0,j=0;
    while(i<lx&&j<ly){
        if(x[i]==y[j]){
            i++;j++;
        }
        else{
            del++;
            i++;
        }
    }
    return del+ly-j+lx-i;
    //return lx-ans[lx-1][ly-1]+ly-ans[lx-1][ly-1];
}

int main()
{
    long long as=1;
    string x="";
    s.push_back("1");
    for(int p=1;as<INF;p++){
        as*=2;
        //cout<<as<<endl;
        if(as<INF){
            long long cp=as;
            while(cp){
                x+=(cp%10+'0');
                cp/=10;
            }
            string k="";
            int len=x.size();
            for(int i=len-1;i>=0;i--){
                k+=x[i];
            }
            s.push_back(k);
            x="";
        }
    }
    int t;
    cin>>t;
    while(t--){
        string num;
        cin>>num;
        //if(num.size()==1&&num[0]<'2')cout<<0
        int len=s.size();
        int ans=INF;
        for(int i=0;i<len;i++){
            //cout<<s[i]<<"-----"<<getmatch(num,s[i])<<endl;
            ans=min(ans,getmatch(num,s[i]));
        }
        cout<<ans<<endl;
    }
}
*/
