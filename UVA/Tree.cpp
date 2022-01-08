#include<iostream>
#include<sstream>
#include<string>
using namespace std;
const int maxn=10000+10;
int inorder[maxn],postorder[maxn],lch[maxn],rch[maxn];
int n,bigans=1000000000,smnode=1000000000;
bool readin(int *a)
{
    string h;
    if(!getline(cin,h)) return false;
    stringstream ss(h);
    int d;n=0;
    while(ss>>d)a[n++]=d;
    return n>0;
}
int build(int L1,int R1,int L2,int R2)
{
    
    if(L1>R1)return 0;   
    int root=postorder[R2];    
    int p=L1;              
    while(inorder[p]!=root)p++; 
    int cnt=p-L1;     
    lch[root]=build(L1,p-1,L2,L2+cnt-1);  
    rch[root]=build(p+1,R1,L2+cnt,R2-1);
    return root;    

}
void dfs(int node,int sum)
{
	sum+=node;  
    if(!lch[node] && !rch[node])
	{
		
		if(sum<bigans ||(sum==bigans && node<smnode))
		{
			bigans=sum;
			smnode=node;
		}
		return;
	} 
    if(lch[node]) dfs(lch[node],sum);
    if(rch[node]) dfs(rch[node],sum);
}
int main()
{
    int head;
    while(readin(inorder))
    {
        readin(postorder);
        build(0,n-1,0,n-1);
        bigans=1000000000;
        dfs(postorder[n-1],0);
        cout<<smnode<<endl;
    }
}