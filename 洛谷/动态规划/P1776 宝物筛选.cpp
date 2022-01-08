#include<bits/stdc++.h>
using namespace std;

const int N=105,W=4e4+10;
struct obj{
	int v,m,w;
}box[N];

int dp[W],q[W],q2[W];

int main()
{
	int n,w;
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		cin>>box[i].v>>box[i].w>>box[i].m;
	}
	for(int i=1;i<=n;i++){
		int c=min(box[i].m,w/box[i].w);
		for(int d=0;d<box[i].w;d++){  //枚举余数，每个余数为一组
			int k=(w-d)/box[i].w;
			int head=0,tail=0;
			for(int j=0;j<=k;j++){  //枚举带的件数
				while(head<tail&&dp[d+j*box[i].w]-j*box[i].v>=q2[tail-1]) 
					tail--;
				q[tail]=j;
				q2[tail++]=dp[d+j*box[i].w]-j*box[i].v;
				while(head<tail&&q[head]<j-c)++head;
				dp[d+j*box[i].w]=max(dp[d+j*box[i].w],q2[head]+j*box[i].v);
			}
		}
	}
		/*
		for(int j=0;j<=box[i].m;j++){
			if(j*box[i].w>w)break;
			
			for(int p=w;p>=j*box[i].w;p--){
				dp[i][p]=max(dp[i][p],dp[i-1][p-j*box[i].w]+(long long)j*box[i].v);				
			}
		}
		*/
	cout<<dp[w]<<endl;
}

