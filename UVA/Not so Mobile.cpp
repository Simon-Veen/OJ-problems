#include<iostream>
using namespace std;
bool ph=1;
int dfs(int a,int b,int c,int d)
{
	int w1,d1,ww,dd;
	
	if(a==0)
	{
		cin>>w1>>d1>>ww>>dd;
		a=dfs(w1,d1,ww,dd);
	}
	if(c==0)
	{
		cin>>w1>>d1>>ww>>dd;
		c=dfs(w1,d1,ww,dd);
	}
	if(a*b!=c*d)ph=0;
	return a+c;	
}
int main()
{
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	int n,w1,w2,d1,d2;
	int cnt=0;
	cin>>n;
	while(n--)
	{
		ph=1;
		cin>>w1>>d1>>w2>>d2;
		dfs(w1,d1,w2,d2);
		if(ph)
		{
			if(cnt)cout<<endl;
			cout<<"YES"<<endl;
		}
		else 
		{
			if(cnt)cout<<endl;
			cout<<"NO"<<endl;
		}
		cnt=1;
	}
}