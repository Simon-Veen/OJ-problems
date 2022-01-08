/*

直接暴力枚举，存答案根据答案剪枝

*/

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<iostream>
using namespace std;
const int MAXN=1e3;
bool vis[27];
vector<char> a[27];
string ans,s,z;
int sum=MAXN;

int get_max(){
    int m=0,x=0,y=0;
    for(int i=0;i<27;i++){
        if(a[i].size()!=0){
            for(int p=0;p<z.size();p++){
                if(z[p]-'A'==i){
                    x=p;
                    break;
                }
            }
            for(int j=0;j<a[i].size();j++){
                char t=a[i][j];
                for(int p=0;p<z.size();p++){
                    if(z[p]==t){
                        y=p;
                        break;
                    }
                }
                if(x!=-1&&y!=-1)m=max(m,abs(y-x));
            }
        }
        x=y=-1;
    }
    return m;
}
void dfs(int s,int f,int maxx){

    maxx=get_max();
    if(maxx>sum){
        return;
    }
    if(s==f){
        if(sum>maxx){
            sum=maxx;
            ans=z;
        }
        return;
    }
    for(int i=0;i<26;i++){
        if(vis[i]){
            z+=char(i+'A');
            vis[i]=0;
            dfs(s+1,f,maxx);
            vis[i]=1;
            z.pop_back();
        }
    }
}
int main()
{
    while(cin>>s){
        if(s[0]=='#')break;

        for(int i=0;i<s.size();i++){
            char t=s[i];
            vis[s[i]-'A']=1;
            i++;
            while(1){
                i++;
                if(s[i]==';'||i==s.size())break;
                a[t-'A'].push_back(s[i]);
                vis[s[i]-'A']=1;
            }
        }
        sum=MAXN;
        int cnt=0;
        for(int i=0;i<27;i++){
            if(vis[i])cnt++;
        }
        dfs(0,cnt,MAXN);
        for(int i=0;i<ans.size();i++){
            printf("%c ",ans[i]);
        }
        printf("-> %d\n",sum);
        s="";
        ans="";
        z="";
        for(int i=0;i<27;i++){
            vis[i]=0;
            a[i].clear();
        }
    }
}
