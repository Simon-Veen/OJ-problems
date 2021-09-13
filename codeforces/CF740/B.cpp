#include<bits/stdc++.h>
using namespace std;
set<int> s;

int main()
{
	int _;
	scanf("%d",&_);
	while(_--){
		int a,b,p,q;
		cin>>a>>b;
		p=(a+b+1)/2;q=(a+b)/2;
		for(int i=0;i<=p;i++){
			int y=(a+i-p);
			if(y<=q&&y>=0){
				s.insert(i+y);
			}
		}
		p=(a+b)/2;q=(a+b+1)/2;
		for(int i=0;i<=p;i++){
			int y=(a+i-p);
			if(0<=y&&y<=q)s.insert(i+y);
		}
		cout<<s.size()<<endl;
		for(auto i:s){
			cout<<i<<" ";
		}
		cout<<endl;
		s.clear();
	}
}