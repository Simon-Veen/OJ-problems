//Good patient!
#include<iostream>
#include<ctype.h>
#include<vector>
#include<string>
using namespace std;
char map[1003][1003];
vector<char> ans;
int n;
void clear()
{
    for(int i=1;i<1000;i++)
        for(int j=1;j<1000;j++)
            map[i][j]=0;
}
bool pan(int t)
{
    int i=1;
    while(map[t][i]!='\n')i++;
    if(map[t][1]=='#' && i==2)return true;

    return false;
}
void dfs(int x,int y)
{
    if(map[x][y]==' '||pan(x)) return;
    else if(map[x][y]=='|') dfs(x+1,y);
    else if(map[x][y]=='-')
    {
        //找到左边界 
        int i;
        for(i=y;;i--)
            if(map[x][i]!='-')break;
        for(i=i+1;;i++)
        {
            if(isprint(map[x+1][i])&&map[x+1][i]!=' ' &&(i==y || map[x-1][i]!='|')) dfs(x+1,i);
            else if(map[x][i]!='-')break;
        }
    }
    else if(isprint(map[x][y]) && map[x][y]!=' ')
    {
        ans.push_back(map[x][y]);
        ans.push_back('(');
        dfs(x+1,y);
        ans.push_back(')');
    }
}
int main()
{
    int x=1,y=1,cy=0;
    char c;
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    cin>>n;
    c=getchar();
    while(n--)
    {
        clear();
        ans.clear();
        x=1;y=1;
        while(1)
        {
            if((c=getchar())==EOF)c='\n';
            //if(n==1 && map[x][y-1]=='#' && c==0)c='\n';
            map[x][y++]=c;
            //if(n==1 && map[x][y-1]==0 &&map[x][y-2]=='#')map[x][y-1]='\n';   
            if(c=='\n') 
            {
                if(pan(x))break;
                x+=1;y=1;
            } 
        }
        x=1;y=1;
        if(map[1][1]=='#'){
            ans.push_back('(');
            ans.push_back(')');
        }
        else
        {
            for(y;;y++)  
                if(isprint(map[1][y]) && map[1][y]!=' ')break;
            ans.push_back('(');
            if(map[x][y]!='#')
                dfs(x,y);
            ans.push_back(')');
        }
        for(int i=0;i<ans.size();i++)
            cout<<ans[i];   
        cout<<endl;   
    }
} 