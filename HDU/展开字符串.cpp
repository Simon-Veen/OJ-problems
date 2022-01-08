#include<iostream>
#include<string>
#include<cctype>
using namespace std;
string dfs()
{
	char b;
	string a;
	while(1)
	{
		b=getchar();
		if(b=='\n'||b==EOF||b==')')return a;
		if(isdigit(b))
		{
			char d;
			string k;
			d=getchar();
			if(isalpha(d))
				for(int i=1;i<=int(b)-48;i++)a+=d;
			else if(d=='(')
			{
				k=dfs();
				for(int i=1;i<=int(b)-48;i++)a+=k;
			}
		}
		else if(isalpha(b))	a+=b;
		else if(b=='(')a+=dfs();
	}
}
int main()
{
	int n;
	char p;
	cin>>n;
	p=getchar();
	for(int i=1;i<=n;i++)
		cout<<dfs()<<endl;
}