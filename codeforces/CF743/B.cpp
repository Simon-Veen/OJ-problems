/*
	有时做不出来再读读题，理解样例。
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,INF=0x3f3f3f3f;
int a[N],b[N];
int sa[N],sb[N];
struct sege{
	int l,r,val;
}tr[N<<2];
void build(int p,int l,int r){
	tr[p].l=l;tr[p].r=r;
	if(l==r){
		tr[p].val=b[l];
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tr[p].val=max(tr[p<<1].val,tr[p<<1|1].val);
}
int find_x(int p,int x){
	if(tr[p].l==tr[p].r){
		if(tr[p].val>=x){
			return tr[p].l;
		}
	}
	if(tr[p<<1].val>=x){
		return find_x(p<<1,x);
	}
	if(tr[p<<1|1].val>=x){
		return find_x(p<<1|1,x);
	}	
}
int main()
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		build(1,1,n);
		int ans=INF;
		for(int i=1;i<=n;i++){
			ans=min(ans,i-1+find_x(1,a[i])-1);
		}
		cout<<ans<<endl;
	}
}