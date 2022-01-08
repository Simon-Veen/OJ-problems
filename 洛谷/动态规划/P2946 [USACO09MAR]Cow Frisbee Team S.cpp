#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10,mod=1e8;
typedef long long ll;
ll dp[N][1005],a[N];
int main()
{
	int n;
	ll f;
	cin>>n>>f;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]%=f;
	}
	for(int i=1;i<=n;i++)dp[i][a[i]]=1;
	for(int i=1;i<=n;i++){
		for(ll j=0;j<f;j++){
			dp[i][j]=((dp[i][j]+dp[i-1][j])%mod+dp[i-1][(j-a[i]+f)%f])%mod;
		}
	}
	cout<<dp[n][0];	
}