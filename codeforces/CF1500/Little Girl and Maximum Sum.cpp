#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
struct sege{
	int l,r;
	ll sum;
}tr[N<<2];
ll b[N],app[N],a[N];
void build(int p,int l,int r){
	tr[p].l=l;tr[p].r=r;
	if(l==r){
		tr[p].sum=app[l];
		return;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tr[p].sum=max(tr[p<<1].sum,tr[p<<1|1].sum);
}
bool change(int p,ll val){

	if(tr[p].l==tr[p].r){
		if(tr[p].sum==0)return 0;
		b[tr[p].l]=val*tr[p].sum;
		tr[p].sum=0;
		return 1;
	}
	if(tr[p<<1].sum==tr[p].sum){
		bool ok=change(p<<1,val);
		tr[p].sum=max(tr[p<<1].sum,tr[p<<1|1].sum);
		return ok;	
	}
	else if(tr[p<<1|1].sum==tr[p].sum){
		bool ok=change(p<<1|1,val);
		tr[p].sum=max(tr[p<<1].sum,tr[p<<1|1].sum);
		return ok;
	}
}

int main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l,r;
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		app[l]++;app[r+1]--;		
	}
	for(int i=1;i<=n;i++){
		app[i]+=app[i-1];
	}
	build(1,1,n);
	for(int i=n;i>=1;i--){
		if(!change(1,a[i])){
			break;
		}
	}
	ll tot=0;
	for(int i=1;i<=n;i++){
		tot+=b[i];
	}
	cout<<tot<<endl;
}
