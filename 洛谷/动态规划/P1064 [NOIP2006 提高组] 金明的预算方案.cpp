#include<bits/stdc++.h>
using namespace std;
const int N=32000+10;
struct node{
	int v,p;
};
vector<node> t[65];
int dp[N];
int main()
{
	int n,m,cnt=1;
	cin>>n>>m;
	for(int i=1,v,p,q;i<=m;i++){
		cin>>v>>p>>q;
		if(q==0){
			node x;
			x.v=v;x.p=p;
			t[i].push_back(x);
		}
		else{
			node x;
			x.v=v;x.p=p;
			t[q].push_back(x);
		}
	}
	for(int i=1;i<=m;i++){
		if(t[i].size()==0)continue;
		for(int p=n;p>=0;p--){
			if(p-t[i][0].v>=0)
				dp[p]=max(dp[p],dp[p-t[i][0].v]+t[i][0].p*t[i][0].v);
			int tot=t[i][1].v+t[i][0].v;
			if(p-tot>=0)
				dp[p]=max(dp[p],dp[p-tot]+t[i][1].p*t[i][1].v+t[i][0].p*t[i][0].v);				
			tot=t[i][2].v+t[i][0].v;
			if(p-tot>=0)
				dp[p]=max(dp[p],dp[p-tot]+t[i][2].v*t[i][2].p+t[i][0].v*t[i][0].p);
			tot=t[i][2].v+t[i][1].v+t[i][0].v;
			if(p-tot>=0)
				dp[p]=max(dp[p],dp[p-tot]+t[i][2].v*t[i][2].p+t[i][1].v*t[i][1].p+t[i][0].p*t[i][0].v);	
		}
	}
	cout<<dp[n];
}