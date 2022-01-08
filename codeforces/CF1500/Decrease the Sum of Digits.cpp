#include<bits/stdc++.h>
using namespace std;
int judge(long long k){
	int sum=0;
	while(k>0){
		sum+=k%10;
		k/=10;
	}
	return sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		long long n,s,ans=0,pw=1;
		cin>>n>>s;
		if(judge(n)<=s){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=18;i++){
			int k=(n/pw)%10;
			long long add=pw*((10-k)%10);
			n+=add;
			ans+=add;
			if(judge(n)<=s){
				break;
			}
			pw*=10;
		}
		cout<<ans<<endl;
	}	
}