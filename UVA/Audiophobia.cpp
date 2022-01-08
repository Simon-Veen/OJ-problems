#include<bits/stdc++.h>
using namespace std;
const int N=105,INF=0x3f3f3f3f;
int G[N][N];
int c,s,q;
void init(){
	for(int i=1;i<=c;i++){
		for(int j=1;j<=c;j++){
			G[i][j]=INF;
		}
	}
}
int main()
{
	int tot=1;
	bool ok=0;
	while(scanf("%d%d%d",&c,&s,&q)!=EOF){
		if(c==0&&s==0&&q==0){
			break;
		}
		if(ok)cout<<endl;
		init();
		for(int i=1;i<=s;i++){
			int from,to;
			cin>>from>>to;
			cin>>G[from][to];
			G[to][from]=G[from][to];
		}
		for(int i=1;i<=c;i++){
			for(int j=1;j<=c;j++){
				for(int p=1;p<=c;p++){
					int ans=max(G[j][i],G[i][p]);
					G[j][p]=min(G[j][p],ans);			
				}
			}
		}
		cout<<"Case #"<<tot++<<endl;
		for(int i=1,from,to;i<=q;i++){
			cin>>from>>to;
			if(G[from][to]!=INF)cout<<G[from][to]<<endl;
			else cout<<"no path"<<endl;
		}
		ok=1;
	}
}