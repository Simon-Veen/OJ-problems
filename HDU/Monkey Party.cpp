#include<cstring>
#include<iostream>
#include<algorithm>

//#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,INF=0x3f3f3f3f;

int a[2*N],s[2*N][2*N];
long long dp[2*N][2*N],sum[2*N];

int main()
{
	int n;
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>a[i];a[n+i]=a[i];
		}
		for(int i=1;i<2*n;i++){
			sum[i]=sum[i-1]+a[i];
			dp[i][i]=0;
			s[i][i]=i;
		}
		for(int i=1;i<2*n;i++){
			for(int j=1;j<2*n;j++)
				if(i!=j)dp[i][j]=INF;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j+i-1<2*n;j++){
				int ed=j+i-1;
				for(int p=s[j][ed-1];p<=s[j+1][ed];p++){
					if(dp[j][ed]>dp[j][p]+dp[p+1][ed]+sum[ed]-sum[j-1]){
						dp[j][ed]=dp[j][p]+dp[p+1][ed]+sum[ed]-sum[j-1];
						s[j][ed]=p;
					}
				}
			
			}
			//out<<i<<endl;
		}		
		long long ans=INF;
		for(int i=1;i+n-1<2*n;i++){
			ans=min(ans,dp[i][i+n-1]);
		}
		cout<<ans<<endl;
	}
}