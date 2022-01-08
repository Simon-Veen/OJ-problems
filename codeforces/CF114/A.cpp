#include<bits/stdc++.h>
using namespace std;
int ans=0;
void print(int n,int t){
	if(n<=0)return;
	if(ans==n)return;	
	cout<<"(";
	ans++;
	if(t>0){
		print(n,t-1);
	}
	cout<<")";
	print(n,t);
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			ans=0;
			print(n,i);
			cout<<endl;
		}
	}
	
	
}