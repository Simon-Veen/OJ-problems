#include<iostream> 
#include<string>
#include<cctype>
#include<map>
#include<cmath>
#include<vector> 
using namespace std;

map<long long int,int> mp;
vector<long long int> bucket;
int cnt; 
void read(int depth)
{
	char a;
	string d;
	while(1)
	{	
		a=getchar();
		if(a==EOF||a=='\n')return;
		else if(a==']')
		{			
			if(d.size()==0)return;
			int len=d.size()-1;
			long long int p=0,k=0;
			int cnt=0;
			for(int i=0;i<d.size();i++)
				p=p*10+(d[i]-'0');	
			k=p*pow(2,depth);
			mp[k]++;
			//cout<<depth<<endl;
			bucket.push_back(k);
			d.clear();
			return;
		}
		else if(a==',')
		{
			if(d.size()==0)continue;
			int len=d.size()-1;
			long long int p=0,k=0;
			int cnt=0;
			for(int i=0;i<d.size();i++)
				p=p*10+(d[i]-'0');	
			k=p*pow(2,depth);
			mp[k]++;
			bucket.push_back(k);
			d.clear();
			read(depth);
			return;
		}
		else if(a=='[')
			read(depth+1);		
		else if(isdigit(a))d+=a;
	}
}
int main()
{
	int n,maxn;
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	cin>>n;
	getchar();
	while(n--)
	{
		maxn=0;
		bucket.clear();
		mp.clear();
		read(0);
		for(int i=0;i<bucket.size();i++) maxn=max(mp[bucket[i]],maxn);
		cout<<bucket.size()-maxn<<endl; 
	}	
}