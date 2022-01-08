#include<iostream>
#include<cstring>
using namespace std;

const int maxn=1000002;
int val[maxn];
void build(int p)
{
    int a;
    cin>>a;
    if(a==-1)return;
    val[p]+=a;
    build(p-1);  //输入下一个左节点 
    build(p+1); //输入下一个右节点 
}

bool read()
{
    int node;
    cin>>node;
    if(node==-1)return false;
    memset(val,0,sizeof(val)); 
    //for(int i=0;i<maxn;i++)val[i]=0;
    val[maxn/2]=node;
    build(maxn/2-1);  //根节点的左节点 
    build(maxn/2+1);      //根节点的右节点 
    return true;
}
int main()
{
   // freopen("1.txt","r",stdin);
   // freopen("2.txt","w",stdout);
    int ptr=0,cnt=1,dd=0;
    while(read())
    {
        ptr=0;
        while(!val[ptr])ptr++;
        cout<<"Case "<<cnt++<<":"<<endl<<val[ptr++];
        while(val[ptr])
            cout<<' '<<val[ptr++];
        cout<<"\n\n";
		dd=1;
    }
} 