#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10,INF=0x3f3f3f3f;
int a[N];
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int maxx=-INF,dif=-INF;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxx=max(maxx,a[i]);
			dif=max(dif,maxx-a[i]);
		}
		int cnt=0;
		while((1LL<<cnt)-1<dif){
			cnt++;
		}
		cout<<cnt<<endl;
	}
}