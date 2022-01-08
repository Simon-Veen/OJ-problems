
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<iostream>

using namespace std;
vector<string> v;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--){
        int n;
        scanf("%d",&n);
        string a,b;
        cin>>a;
        v.clear();
        for(int i=2;i<=n;i++){
            cin>>b;
            v.push_back(b);
        }
        int lena=a.size();
        string cp,ans="";
        for(int i=0;i<lena;i++){
            for(int j=i+2;j<lena;j++){
                cp="";
                for(int p=i;p<=j;p++) cp+=a[p];  //获得字串
                bool ok=1;
                for(int p=0;p<v.size();p++){   //依次匹配
                    int l=v[p].size();
                    ok=1;
                    for(int k=0;k<l;k++){
                        if(v[p][k]==cp[0]){
                            int ptr=0;
                            while(v[p][ptr+k]==cp[ptr]){
                                ptr++;
                                if(ptr==cp.size())break;
                            }
                            if(ptr==cp.size()){
                                ok=0;
                                break;
                            }
                        }
                    }
                    if(ok==1)break;
                }
                if(ok==0&&cp.size()>=3){
                    if(ans.size()<cp.size()){
                        ans=cp;
                    }
                    else if(ans.size()==cp.size()){
                        if(ans>cp)ans=cp;
                    }
                }
            }
        }
        if(ans.size()<3)cout<<"no significant commonalities"<<endl;
        else cout<<ans<<endl;
    }
}