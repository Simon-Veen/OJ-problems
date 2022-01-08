
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
const int N=1e4+10,M=5e3+10,INF=0x3f3f3f3f;
int a[N],dp[N][M],s[N][M];

int main()
{
	int t,n,m;
	while(cin>>t){
		for(int _=1;_<=t;_++){
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			sort(a+1,a+1+n);
			for(int i=2;i<=n;i++){
				dp[i][1]=(a[i]-a[1])*(a[i]-a[1]);
				s[i][i]=i;
				for(int j=2;j<=m;j++){
					dp[i][j]=INF;
					for(int p=s[i-1][j];p<i;p++){
						if(dp[i][j]>dp[p][j-1]+(a[i]-a[p+1])*(a[i]-a[p+1])){
							dp[i][j]=dp[p][j-1]+(a[i]-a[p+1])*(a[i]-a[p+1]);	
							s[i][j]=p;
						}
					}
				}
			}
			cout<<"Case "<<_<<": "<<dp[n][m]<<endl;
		}
	}	
}