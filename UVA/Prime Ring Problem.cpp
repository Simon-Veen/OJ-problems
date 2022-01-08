#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int a[30];
bool v[30];
int n;
bool isprimer(int k)
{
	if(k<=1)return 0;
	for(int i=2;i<=sqrt(k);i++)
		if(k%i==0)return 0;
	return 1;
}
void build(int cur)
{
	if(cur==n&&isprimer(a[cur-1]+a[0]))
	{
		for(int i=0;i<n;i++)
		{
			if(i!=0)printf(" ");
			printf("%d",a[i]);	
		}
		printf("\n");
		return;	
	}
	for(int i=2;i<=n;i++)
	{
		if(!v[i]&&isprimer(i+a[cur-1]))
		{
			a[cur]=i;
			v[i]=1;
			build(cur+1);
			v[i]=0;
		}
	}
}
int main()
{ 
	int cnt=1;
	isprimer(30);
	while(cin>>n)
	{
		a[0]=1;
		v[1]=1;
		if(cnt>1)printf("\n");
		printf("Case %d:\n",cnt++);
		build(1);	
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
	}
		
} 