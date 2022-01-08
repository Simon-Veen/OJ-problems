/*
	和一定时差小积大
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e16;
int a[14];
ll sum=1,k;
char cf[14]={'.','c','o','d','e','f','o','r','c','e','s'};
bool judge()
{
	sum=1;
	for(int i=1;i<=10;i++){
		sum*=a[i];
	}
	return sum>=k;
}
int main()
{
	cin>>k;
	int cnt=1;
	for(int i=1;i<=10;i++)a[i]=1;
	while(!judge()){
		a[cnt++]++;
		cnt%=11;
	}
	for(int i=1;i<=10;i++){
		for(int j=1;j<=a[i];j++){
			cout<<cf[i];
		}
	}
}