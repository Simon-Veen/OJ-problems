#include<bits/stdc++.h>
using namespace std;
const int N=30;
map<string,int> ma;
int n,m,G[N][N];
bool vis[N];
string find_name(int i){
	for(auto s=ma.begin();s!=ma.end();s++){
		if(s->second==i){
			return s->first;
		}
	}
}

int main(){
	bool sss=0;int tt=1;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0)break;
		if(sss)cout<<endl;
		string f,t;
		int cnt=1;
		for(int i=1;i<=m;i++){
			cin>>f>>t;
			if(!ma.count(f))ma[f]=cnt++;
			if(!ma.count(t))ma[t]=cnt++;
			G[ma[f]][ma[t]]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int p=1;p<=n;p++){
					G[j][p]=G[j][p]|(G[j][i]&&G[i][p]);
				}
			}
		}
		cout<<"Calling circles for data set "<<tt++<<":"<<endl;
		for(int i=1;i<=n;i++){
			bool ok=0;
			if(vis[i])continue;
			cout<<find_name(i);
			vis[i]=1;
			for(int j=1;j<=n;j++){
				if(G[i][j]&&G[j][i]){
					if(!vis[j]){
						vis[j]=1;
						cout<<", "<<find_name(j);
					}
				}
			}
			cout<<endl;
		}
		sss=1;		
		memset(vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		ma.clear();
	}
}