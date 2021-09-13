#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll dp[N];
ll n,m,sum,tot=1; 
int main()
{
	int id=1;
	cin>>n>>m;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=(dp[i]+tot)%m;
		id=2;
		while(i/id>=1){
			int q=i/id;
			int r=i/q;
			dp[i]=((dp[i]+(dp[q]*(r-id+1))%m))%m;
			//dp[i]=(dp[i]+dp[i/id])%m;
			id+=(r-id+1);
		}
		tot=(tot+dp[i])%m;
	}
	cout<<dp[n]<<endl;
}