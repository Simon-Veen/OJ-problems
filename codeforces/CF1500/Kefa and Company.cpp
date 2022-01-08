/*
	悔步贪心维护答案序列
	1.把所有人按照钱数从小到大排序
	2.把第一个放到序列中。
	3.对于每一个数，判断能否放进序列中：
		a.如果可以放进，就放
		b.不能放的话判断以下，如果该友谊值比序列之和更大，则重开一个序列
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int m,v;
	bool operator < (const node &k){
		return m<k.m;
	}
}a[N];
typedef long long ll;
ll prefix[N];
int main()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].v;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		prefix[i]=prefix[i-1]+a[i].v;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		node k;
		k.m=a[i].m+d;k.v=a[i].v;
		int j=lower_bound(a+i,a+n+1,k)-a-1;
		ans=max(ans,prefix[j]-prefix[i-1]);
	}
	cout<<ans<<endl;
}