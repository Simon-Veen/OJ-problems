
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,INF=0x3f3f3f3f;
struct node{
	int v=0,t;
	string name;
	bool operator < (const node &k){
		return v>k.v;
	}
}a[N];
int main(){
	int t;
	cin>>t;
	map<string,int> m;
	vector<pair<string,int> > v;
	int cnt=0,tot=0;
	for(int i=1;i<=t;i++){
		string name;
		int score;
		cin>>name>>score;
		v.push_back({name,score});
		if(!m.count(name)){
			m[name]=cnt++;
		}
		a[m[name]].v+=score;
		a[m[name]].name=name;
	}
	sort(a,a+cnt);
	int maxx=a[0].v,mint=INF;
	string win="";
	for(int i=0;i<cnt;i++){
		if(a[i].v==maxx){
			int sum=0;
			for(int j=0;j<t;j++){
				if(v[j].first==a[i].name){
					sum+=v[j].second;
					if(sum>=maxx){
						if(j<mint){
							mint=j;
							win=a[i].name;
						}
						break;
					}
				}
			}
		}
		else break;
	}
	cout<<win<<endl;
}