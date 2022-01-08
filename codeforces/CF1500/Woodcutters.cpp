#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,INF=-1e9-10;
struct node{
	int h,x;
	bool operator < (const node &k){
		return x<k.x;
	}
}t[N];
int stat[N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].x>>t[i].h;
	}
	sort(t+1,t+1+n);
	t[0].x=INF;t[0].h=INF;stat[0]=1;
	t[n+1].x=-INF-INF;
	//cout<<t[n+1].x<<endl;
	int ans=0;
	//cout<<t[0].x<<endl;
	for(int i=1;i<=n;i++){
	
		if(stat[i-1]==1||stat[i-1]==2){  //上一个没砍
			if(t[i].x-t[i].h>t[i-1].x){ //可以左倒
				stat[i]=2;
				ans++;
				//cout<<i<<" "<<stat[i]<<endl;
				continue;
			}

		}
		else if(stat[i-1]==3){ //上一个右倒
			if(t[i].x-t[i].h>t[i-1].x+t[i-1].h){ //
				stat[i]=2;
				ans++;
				//cout<<i<<" "<<stat[i]<<endl;
				continue;
			}
		}
		if(t[i].x+t[i].h<t[i+1].x){ //可以左倒
			stat[i]=3;
			ans++;
			//cout<<i<<" "<<stat[i]<<endl;
			continue;
		}
		stat[i]=1;
	}
	cout<<ans<<endl;
}