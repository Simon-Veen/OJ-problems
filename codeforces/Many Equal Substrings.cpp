#include<iostream>
#include<string>
using namespace std;
string c,cp,k;
int nxt[100];
int main()
{
	int a,b;
	cin>>a>>b;
	cin>>c;
	nxt[0]=0;
	int j=0,i=1;
	while(i!=a)
	{
		if(c[i]==c[j])
		{
			j++;
			nxt[i]=j;	
			i++;
		}
		else if(j==0)
		{
			nxt[i]=0;
			i++;
		}
		else j=nxt[j-1];
	}
	int maxx=nxt[a-1];
	for(int i=maxx;i<a;i++) cp+=c[i];
	for(int i=1;i<b;i++) k+=cp;
	cout<<c+k<<endl;
}