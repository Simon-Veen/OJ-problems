#include<bits/stdc++.h>
using namespace std;
const int N=4e6+10;
typedef long long ll;
ll dp[N],a[N],n,m,tot;
int main()
{
	cin>>n>>m;
	dp[1]=1;
	for(ll i=1;i<=n;i++){
		a[i]=(a[i]+a[i-1])%m;
		dp[i]=((dp[i]+tot)%m+a[i])%m;
		for(ll j=2;j*i<=n;j++){
			ll l=j*i,r=j*i+j-1;
			r=min(r,n+1);
			a[l]=(a[l]+dp[i])%m;
			a[r+1]=(a[r+1]-dp[i]+m)%m;
		}
		tot=(tot+dp[i])%m;
	}
	cout<<dp[n]<<endl;
}