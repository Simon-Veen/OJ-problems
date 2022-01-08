/*
	完全背包写法
	速度上和记忆化搜索差不多
*/
#include<bits/stdc++.h>
using namespace std;
const int N=25000+10;
int dp[N],a[105];
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,ans;
		cin>>n;
		ans=n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		dp[0]=1;
		for(int i=1;i<=n;i++){
			if(dp[a[i]]){
				ans--;
				continue;
			}
			for(int j=a[i];j<=a[n];j++){
				dp[j]=dp[j]|dp[j-a[i]];
			}
		}
		cout<<ans<<endl;
		memset(dp,0,sizeof(dp));
	}
}
/*
记忆化搜索

#include<bits/stdc++.h>
using namespace std;
const int N=25010;
int a[N];
vector<int> ans;
int vis[N];
bool dfs(int k,int len){
	if(k<0)return 0;
	if(k==0)return 1;
	if(vis[k]!=-1){
		return vis[k];
	}
	for(int j=0;j<len;j++){
		if(dfs(k-ans[j],len)){
			vis[k]=1;
			return 1;
		}
	}
	vis[k]=0;
	return 0;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<N;i++)vis[i]=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];		
		}
		sort(a+1,a+1+n);
		ans.push_back(a[1]);
		vis[a[1]]=1;
		for(int i=2;i<=n;i++){
			bool ok=dfs(a[i],ans.size());
			if(!ok){
				ans.push_back(a[i]);
				vis[a[i]]=1;
			}
		}
		cout<<ans.size()<<endl;
		ans.clear();
	}
}
*/