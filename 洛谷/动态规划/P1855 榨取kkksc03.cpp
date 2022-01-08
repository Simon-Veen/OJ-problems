#include<bits/stdc++.h>
using namespace std;
const int N=200+10;
int dp[N][N];

struct node{
	int t,m;
}all[N];

int main()
{
	int n,m,t;
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++){
		cin>>all[i].m>>all[i].t;
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=all[i].m;j--){
			for(int p=t;p>=all[i].t;p--){
				dp[j][p]=max(dp[j][p],dp[j-all[i].m][p-all[i].t]+1);
			}
		}
	}
	cout<<dp[m][t]<<endl;
}