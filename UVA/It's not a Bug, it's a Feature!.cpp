/*
	1.建图，每个节点包括两部分，可用结构体
	2。扫描初始点，用dijkstra跑，对于每个节点，如果第一部分全都是0
	或者全都是-，就可以放进队列，放进队列前标记当前状态，保证不重复
	3.直到全为+，就停止
*/
#include<bits/stdc++.h>
using namespace std;
const int N=105,INF=0x3f3f3f3f;
int n,m;

struct pitch{
	int c;
	string bef,aft;
}p[N];
struct node{
	int c,s;
	bool operator < (const node &k)const {
		return c>k.c;
	}
};
int d[1<<20];
bool vis[1<<20];
void dijkstra(){
	for(int i=0;i<(1<<20);i++){
		d[i]=INF;vis[i]=0;
	}
	priority_queue<node> q;
	d[(1<<n)-1]=0;  //相当于n个1
	q.push((node){0,(1<<n)-1});
	while(q.size()){
		node head=q.top();q.pop();
		if(head.s==0){
			break;
		}
		if(vis[head.s])continue;
		vis[head.s]=1;

		for(int i=1;i<=m;i++){
			bool ok=1;
			string pp=p[i].bef;
			for(int j=0;j<n;j++){
				if(pp[j]=='+'&&!(head.s&(1<<j))){//判断是否能匹配上
					ok=0;break;		
				}
				if(pp[j]=='-'&&(head.s&(1<<j))){//即head.s的第j位必须是0
					//否则
					ok=0;break;
				}
			}
			if(!ok)continue;//该条件匹配不上
			int x=head.s;
			string cp=p[i].aft;
			for(int j=0;j<n;j++){
				if(cp[j]=='+'){
					x|=(1<<j);
				}
				if(cp[j]=='-'){
					x&=~(1<<j);
				}
			}
			if(d[x]>d[head.s]+p[i].c){
				d[x]=d[head.s]+p[i].c;
				q.push((node){d[x],x});
			}
		}
	}
	//while(q.size())q.pop();
}

int main()
{
	int tt=1;bool ok=0;
	while(cin>>n>>m){
		if(n==0&&m==0)break;
		for(int i=1;i<=m;i++){
			cin>>p[i].c>>p[i].bef>>p[i].aft;	
		}
		cout<<"Product "<<tt++<<endl;
		dijkstra();
		if(d[0]==INF)cout<<"Bugs cannot be fixed."<<endl;
		else cout<<"Fastest sequence takes "<<d[0]<<" seconds."<<endl;
		cout<<endl;
	}	
}