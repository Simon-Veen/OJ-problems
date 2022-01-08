#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std; 
char map[70][70];
long long int node_cnt=0;;
vector<int> bcnt;
vector<int> ccnt;
string h;
queue<int> rebuild;
void pro()
{
	int ct=bcnt.size()-1,len=0;
	int sum=0;
	while(bcnt[ct])
	{
		sum=sum*10+bcnt[ct];
		len++;
		ct--;
	}
	int dec=0;
	ct=0;
	while(ct<=len-1)
	{
		dec+=(sum%10)*pow(5,ct++);
		sum/=10;
	}
	ccnt.push_back(dec);
}
bool dividtree(int x1,int y1,int x2,int y2,int node)
{
	bool bc=0,wc=0;
	for(int i=x1;i<=x2;i++)
	{
		for(int j=y1;j<=y2;j++)
		{
			if(bc&&wc)break;
			if(map[i][j]=='1'&&!bc)
				bc=1;
			if(map[i][j]=='0'&&!wc)
				wc=1; 
		}
	}
	if(wc&&!bc)
	{
		bcnt.pop_back();
		return 0; //表示没有黑点 
	}
	if(!wc&&bc)
	{
		bcnt.push_back(node);
		pro();
		bcnt.pop_back(); 
		node_cnt++;
		return 1;  //表示有黑点	
	}
	bool have=0;
	if(wc&&bc)//这里改成pop一个节点 
	{
		bcnt.push_back(node);
		if(dividtree(x1,y1,(x1+x2)/2,(y1+y2)/2,1))
		{
			have=1;
			bcnt.pop_back();
		}
		bcnt.push_back(node);
		if(dividtree(x1,(y1+y2)/2+1,(x1+x2)/2,y2,2))
		{
			have=1;
			bcnt.pop_back();
		}
		bcnt.push_back(node);
		if(dividtree((x1+x2)/2+1,y1,x2,(y1+y2)/2,3))
		{
			have=1;
			bcnt.pop_back();
		}
		bcnt.push_back(node);
		if(dividtree((x1+x2)/2+1,(y1+y2)/2+1,x2,y2,4))
		{	
			have=1;	
			bcnt.pop_back();
		}
		if(have)return 1;
	} 
} 
void maketree(int x1,int y1,int x2,int y2)
{
	if(rebuild.empty())
	{
		for(int i=x1;i<=x2;i++)
			for(int j=y1;j<=y2;j++)
				map[i][j]='*';
		return;
	}
	int k=rebuild.front();
	rebuild.pop();
	if(k==1)
	{
		maketree(x1,y1,(x1+x2)/2,(y1+y2)/2);
	}
	else if(k==2)
	{
		maketree(x1,(y1+y2)/2+1,(x1+x2)/2,y2);
	}
	else if(k==3)
	{
		maketree((x1+x2)/2+1,y1,x2,(y1+y2)/2);
	}
	else if(k==4)
	{
		maketree((x1+x2)/2+1,(y1+y2)/2+1,x2,y2);
	}
}
int main()
{
	int n,cnt=1;
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	while(cin>>n&&n!=0)
	{
		node_cnt=0;
		if(cnt>1)cout<<endl;
		if(n>0)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>h;
				for(int j=0;j<h.size();j++)
					map[i][j+1]=h[j];
				h.clear();
			}
			dividtree(1,1,n,n,0); 
			if(cnt>1)cout<<endl;
			printf("Image %d\n",cnt++);
			sort(ccnt.begin(),ccnt.end());
			int t=1;
			for(int i=0;i<ccnt.size();i++)
			{
				if(i!=0&&i%12!=0)printf(" ");
				printf("%d",ccnt[i]);
				
				if(t%12==0&&i!=ccnt.size()-1)cout<<endl;
				t++;
			}
			if(ccnt.size()!=0)printf("\nTotal number of black nodes = %lld",node_cnt);
			else printf("Total number of black nodes = %d",node_cnt);
			bcnt.clear();
			ccnt.clear();			

			node_cnt=0;
		}
		else
		{
			int a,k,ct=0;
			for(int i=1;i<=-n;i++)
				for(int j=1;j<=-n;j++)
					map[i][j]='.';
			while(cin>>a)
			{
				if(a==-1)break;
				while(a)
				{	
					rebuild.push(a%5);
					a=a/5;
			 	}
				maketree(1,1,-n,-n); 	
			}
			if(cnt>1)cout<<endl;
			printf("Image %d\n",cnt++);
			for(int i=1;i<=-n;i++)
			{
				for(int j=1;j<=-n;j++)
					cout<<map[i][j];
				if(i!=-n)cout<<endl;
			}
			for(int i=0;i<=-n;i++)
				for(int j=0;j<=-n;j++)
					map[i][j]=0;	
		}
	}
	cout<<endl;
}