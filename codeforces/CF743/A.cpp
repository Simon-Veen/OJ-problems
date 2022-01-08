#include<bits/stdc++.h>
using namespace std;

char a[105];

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>a;
		int len=strlen(a);
		int ans=0;
		if(a[len-1]-'0'>0)ans+=(a[len-1]-'0');
		for(int i=len-2;i>=0;i--){
			if((a[i]-'0')>0){
				ans+=(a[i]-'0')+1;
			}
		}
		cout<<ans<<endl;
	
	}
}