#include<bits/stdc++.h>
using namespace std;

const int N=1000+10,INF=0x3f3f3f3f;
typedef long long ll;
int fa[N],n,q,cnt;
ll c[10],ans=0;
vector<int> v[10];
struct point{
	ll X,Y;
}p[N];
struct edge{
	int f,t;
	ll c;
	bool operator < (const edge &k){
		return c<k.c;
	}
}e[N*N];
vector<edge> kru;
void init_fa()
{
	for(int i=1;i<=n;i++)fa[i]=i;
}
int dis(ll x,ll y,ll x1,ll y1){
	return (x-x1)*(x-x1)+(y-y1)*(y-y1);
}
int father(int s){
	return fa[s]==s?s:fa[s]=father(fa[s]);
}
void dfs(int now,string s){
	if(now>q){
		if(s=="")return;
		init_fa();
		int tot=0;ll maxx=0;
		bool ok=0;
		for(int i=0;i<s.size();i++){
			int ptr=s[i]-'0';
			int len=v[ptr].size();
			int head=father(v[ptr][0]);
			maxx+=c[ptr];
			for(int j=1;j<len;j++){
				int ft=father(v[ptr][j]);
				if(head!=ft){
					fa[ft]=head;
					tot++;
					if(tot==n-1){
						ok=1;
						break;
					}
				}
			}
			if(ok)break;
		}
		if(!ok){
			int len=kru.size();
			for(int i=0;i<len;i++){
				int fs=father(kru[i].f);
				int ft=father(kru[i].t);
				if(fs!=ft){
					fa[ft]=fs;
					tot++;
					maxx+=kru[i].c;
					if(tot==n-1){
						ok=1;
						break;
					}
				}
			}
		}
		if(ok)ans=min(ans,maxx);
		return;
	}
	dfs(now+1,s+(char)(now+'0'));
	dfs(now+1,s);
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n>>q;
		for(int i=1,m;i<=q;i++){
			cin>>m>>c[i];
			for(int j=1,node;j<=m;j++){
				cin>>node;
				v[i].push_back(node);
			}
		}
		cnt=1;
		for(int i=1;i<=n;i++)cin>>p[i].X>>p[i].Y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				e[cnt].f=i;e[cnt].t=j;
				e[cnt++].c=dis(p[i].X,p[i].Y,p[j].X,p[j].Y);
			}
		}
		init_fa();
		sort(e+1,e+cnt);
		int tot=0;
		ans=0;
		for(int i=1;i<cnt;i++){
			int fs=father(e[i].f);
			int ft=father(e[i].t);
			if(fs!=ft){
				fa[ft]=fs;
				kru.push_back(e[i]);
				tot++;
				ans+=e[i].c;
				if(tot==n-1)break;
			}
		}
		dfs(1,"");
		cout<<ans<<endl;
		if(t)cout<<endl;
		kru.clear();
		for(int i=1;i<=q;i++)v[i].clear();
	}
}