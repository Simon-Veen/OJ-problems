#include<iostream>
#include<string>
using namespace std;
string len,dir;
int main()
{
	int n,is,l,r,cnt=1,k=0;
	string t;
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	while(1)
	{
		cin>>n;
		if(n==0)break;
		for(int i=1;i<=n;i++)cin>>t;
		len.clear();
		cin>>len;
		cin>>is;
		cout<<"S-Tree #"<<cnt++<<":"<<endl;
		for(int i=0;i<is;i++)
		{
			cin>>dir;	
			l=0;r=len.size()-1;
			for(int j=0;j<dir.size();j++)
			{
				if(dir[j]=='0') r=(l+r)/2;
				else l=(l+r)/2+1;
			}
			if(l>r)cout<<len[l];
			else cout<<len[r];
			dir.clear();
		}
		cout<<endl<<endl;
	}	
} 