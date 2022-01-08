#include<bits/stdc++.h>
using namespace std;
const int N=105,INF=0x3f3f3f3f;
struct edge{
	int s,t,c;
	bool operator < (const edge k){
		return c<k.c;
	}
}e[N*N];
int fa[N*N];
int n,m;

int father(int p){
		return fa[p]==p?p:fa[p]=father(fa[p]);
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0)break;
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&e[i].s,&e[i].t,&e[i].c);
		}
		sort(e+1,e+1+m);
		int minn=INF;
		for(int i=1;i<=m;i++){
			for(int p=1;p<=n;p++)fa[p]=p;
			int mx=0,mi=INF,t=0;
			bool ok=0;
			for(int j=i;j<=m;j++){
				int fs=father(e[j].s);
				int ft=father(e[j].t);
				if(fs!=ft){
					fa[ft]=fs;
					mx=max(mx,e[j].c);
					mi=min(mi,e[j].c);
					t++;
					if(t==n-1){
						ok=1;
						break;
					}
				}
			}
			if(ok)minn=min(minn,mx-mi);
		}
		if(minn==INF)minn=-1;
		printf("%d\n",minn);
	}	
}