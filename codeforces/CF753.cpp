
/*
    codeforces 753 div3

*/

/*
    F:

    需要找到每一个最大环.
    强连通分量

*/
#include<bits/stdc++.h>

using namespace std;
const int N=2e3+10;
char board[N][N];
int val[N][N],vis[N][N];
int n,m,cnt=0;

bool judge(int x,int y){
    if(x<=n&&x>=1&&y<=m&&y>=1)return true;
    return false;
}

int dfs(int x,int y){
    if(vis[x][y]==cnt){

        return 0;
    }
    else if(vis[x][y]!=0)return val[x][y];

    vis[x][y]=cnt;
    if(board[x][y]=='R'&&judge(x,y+1)){
        int del=dfs(x,y+1);
        //cout<<del<<" "<<x<<" "<<y<<endl;
        if(del!=0)val[x][y]+=del; //不咬尾
        else return 0;

    }
    else if(board[x][y]=='L'&&judge(x,y-1)){
        int del=dfs(x,y-1);
        //cout<<del<<" "<<x<<" "<<y<<endl;
        if(del!=0)val[x][y]+=del; //不咬尾
        else return 0;

    }
    else if(board[x][y]=='D'&&judge(x+1,y)){
        int del=dfs(x+1,y);
        //cout<<del<<" "<<x<<" "<<y<<endl;

        if(del!=0)val[x+1][y]+=del; //不咬尾
        else return 0;

    }
    else if(board[x][y]=='U'&&judge(x-1,y)){
        int del=dfs(x-1,y);
       // cout<<del<<" "<<x<<" "<<y<<endl;
        if(del!=0)val[x][y]+=del; //不咬尾
        else return 0;

    }
    return val[x][y];
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>board[i][j];
                val[i][j]=1;
                vis[i][j]=0;
            }
        }
        cnt=0;
       // cout<<"Done"<<endl;
        int ans=0,ans_x=1,ans_y=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j]==0){
                    cnt++;
                    int v=dfs(i,j);
                    if(v==0){
                        int tot=0;
                        for(int i=1;i<=n;i++){
                            for(int j=1;j<=m;j++){
                                if(vis[i][j]==cnt)tot++;
                            }
                        }
                        //cout<<"here tot"<<tot<<" "<<i<<" "<<j<<endl;
                        for(int i=1;i<=n;i++){
                            for(int j=1;j<=m;j++){
                                if(vis[i][j]==cnt){
                                    val[i][j]=max(val[i][j],tot);
                                }
                            }
                        }
                    }
                   // cout<<v<<endl;
                }
                if(val[i][j]>ans){
                    ans=val[i][j];
                    ans_x=i;ans_y=j;
                }
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<ans_x<<" "<<ans_y<<" "<<ans<<endl;
    }
}


/*
E
const int N=1e6+10;
char x[N];
struct x_y{
    int x=0,y=0;
};
int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        scanf("%s",x);
        int len=strlen(x),ans_x=1,ans_y=1,bx=0,by=0;
        x_y lu,ld,ru,rd;
        for(int i=0;i<len;i++){
            if(x[i]=='L'){
                by-=1;
                if(by<lu.y)lu.y=by;
                if(by<ld.y)ld.y=by;
            }
            else if(x[i]=='R'){
                by+=1;
                if(by>ru.y)ru.y=by;
                if(by>rd.y)rd.y=by;
            }
            else if(x[i]=='U'){
                bx-=1;
                if(lu.x>bx)lu.x=bx;
                if(ru.x>bx)ru.x=bx;
            }
            else if(x[i]=='D'){
                bx+=1;
                if(ld.x<bx)ld.x=bx;
                if(rd.x<bx)rd.x=bx;
            }
            int cx=ld.x-lu.x+1,cy=rd.y-ld.y+1;
            if(cx<=n&&cy<=m){
                ans_x=abs(lu.x)+1;ans_y=abs(lu.y)+1;
            }
            else break;
        }

        cout<<ans_x<<" "<<ans_y<<endl;
    }


}
*/




/*

D

const int N=2e5+10;
struct data{
    int a;
    char b;
}d[N];
char x[N];
bool cmp(const data &i,const data &j){
    return i.a<j.a;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>d[i].a;
        scanf("%s",x+1);
        for(int i=1;i<=n;i++)d[i].b=x[i];
        sort(d+1,d+1+n,cmp);
        int cnt=1,tail=n;
        bool ans=1;
        //B first
        for(int i=1;i<=n;i++){
            if(d[i].b=='B'){
                if(d[i].a>=cnt)cnt++;
                else{
                    ans=0;break;
                }
            }
        }
        //A second
        for(int i=1;i<=n;i++){
            if(d[i].b=='R'){
                if(d[i].a<=cnt)cnt++;
                else{
                    ans=0;break;
                }
            }
        }
        if(cnt!=n+1)ans=0;
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
*/
/*
C
const int N=2e5+10;
int a[N];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+1+n);
        int ans=a[1];
        for(int i=2;i <=n;i++)
             ans = max(ans,a[i]-a[i-1]);
        cout << ans <<endl;
    }

}*/
/*
B
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long int x,n;
        cin>>x>>n;
        if(x%2==0){
            if(n%4==0)cout<<x<<endl;
            else if(n%4==1)cout<<x-n<<endl;
            else if(n%4==2)cout<<x+1<<endl;
            else if(n%4==3)cout<<x+1+n<<endl;
        }
        else{
            if(n%4==0)cout<<x<<endl;
            else if(n%4==1)cout<<x+n<<endl;
            else if(n%4==2)cout<<x-1<<endl;
            else if(n%4==3)cout<<x-1-n<<endl;
        }
    }

}
*/
/*

A

map<char,int> m;
string x,g;
int main()
{
    int t,ans;
    cin>>t;
    while(t--){
        cin>>x>>g;
        ans=0;
        int lx=x.size(),lg=g.size();
        for(int i=0;i<lx;i++){
            m[x[i]]=i+1;
        }
        for(int i=0;i<lg-1;i++){
            ans+=abs((m[g[i+1]]-m[g[i]]));
        }
        cout<<ans<<endl;
        m.clear();

    }
}
*/
