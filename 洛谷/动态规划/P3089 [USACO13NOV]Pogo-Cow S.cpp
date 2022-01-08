#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,INF=0x3f3f3f3f;
struct node{
	int g,x;
	bool operator < (const node &p)const {
		return x<p.x;
	}
}p[N];
int dp[N][N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].g;
	}
	sort(p+1,p+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		dp[i][i]=p[i].g;
		for(int j=1;j<i;j++){
			for(int k=1;k<=j;k++){
				if(p[i].x-p[j].x>=p[j].x-p[k].x)
				{
					dp[i][j]=max(dp[j][k]+p[i].g,dp[i][j]);
					//ans=max(ans,dp[i][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,dp[i][j]);
		}
	}
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][i]=p[n-i+1].g;
		for(int j=1;j<i;j++){
			for(int k=1;k<=j;k++){
				if(p[n-j+1].x-p[n-k+1].x>=p[n-i+1].x-p[n-j+1].x){
					dp[i][j]=max(dp[i][j],dp[j][k]+p[n-i+1].g);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
}