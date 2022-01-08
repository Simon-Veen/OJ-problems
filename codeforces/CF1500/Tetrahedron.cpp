#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,N=1e7+10;
long long dp[N];
int main()
{
	int n;
	cin>>n;
	dp[1]=0;dp[2]=3;
	for(int i=3;i<=n;i++){
		dp[i]=((2*dp[i-1])%mod+(3*dp[i-2])%mod)%mod;
	}
	cout<<dp[n]<<endl;
}