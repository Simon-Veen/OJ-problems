#include<cstdio>
#include<iostream>
using namespace std;

int box[100005];
int n,m,INF=0x7FFFFFFF;
bool judge(int k)
{
    int sum=0,cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(sum+box[i]<=k)sum+=box[i];
        else {
            sum=box[i];
            cnt++;
        }
    }
    return cnt<=m;
}
int main()
{
    //reopen("1.txt","r",stdin);
    cin>>n>>m;//scanf("%d%d",&n,&m);
    int left=0,right=1e9;
    for(int i=1;i<=n;i++)
    {
        cin>>box[i];//scanf("%d",&box[i]);
        left=max(left,box[i]);
        //right+=box[i];
    }
    int mid;
    while(left<right)
    {
        mid=(left+right)>>1;
        if(judge(mid))right=mid;
        else left=mid+1;
    }
    cout<<left;//printf("%d\n",left);
}
