#include<bits/stdc++.h>
using namespace std;
char dc[55];
int n;
vector<string> th;
int dp[55][55];
bool isprime(int x){
	if(x==1)return false;
	int len=sqrt(x);
	for(int i=2;i<x;i++){
		if(x%i==0)return false;
	}
	return true;
}

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=99;i++){
		if(!isprime(i)){
			string x="";
			if(i>=10){
				x=char(i/10+'0');
				x+=char(i%10+'0');
			}
			else x=char(i+'0');
			th.push_back(x);
		}
	}
	while(t--){
		cin>>n;
		scanf("\n%s",dc);
		int cnt=th.size();
		for(int i=0;i<cnt;i++){
			memset(dp,0,sizeof(dp));
			int len=th[i].size();
			for(int j=0;j<n;j++){
				for(int p=0;p<len;p++){
					if(th[i][p]==dc[j]){
						if(p&&j)dp[p][j]=dp[p-1][j-1]+1;
						else dp[p][j]=1;
					}
					if(p)dp[p][j]=max(dp[p-1][j],dp[p][j]);
					if(j)dp[p][j]=max(dp[p][j-1],dp[p][j]);	
				}
			}
			if(dp[len-1][n-1]==th[i].size()){
				cout<<th[i].size()<<endl<<th[i]<<endl;
				break;
			}		
		}
	}
}