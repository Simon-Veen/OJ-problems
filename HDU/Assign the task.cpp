#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=5e4+10;
struct segement{
    int l,r,task;
    int lazy;
}t[MAXN<<2];
vector<int> v[MAXN];
int in[MAXN],cnt;
map<int,int> m;
void build(int h){

    int len=v[h].size();
    t[m[h]].task=-1;
    t[m[h]].lazy=0;
    if(len!=0) t[m[h]].l=cnt;
    else{
        t[m[h]].l=t[m[h]].r=m[h];
        return;
    }
    for(int i=0;i<len;i++){
        m[v[h][i]]=cnt++;
        build(v[h][i]);
    }
    t[m[h]].r=cnt-1;
}
void pushdown(int p){

    if(t[m[p]].lazy){
        int len=v[p].size();
        for(int i=0;i<len;i++){
            t[m[v[p][i]]].task=t[m[p]].lazy;
            t[m[v[p][i]]].lazy=t[m[p]].lazy;
        }
        t[m[p]].lazy=0;
    }
}  
int ask(int p,int g){
    int len=v[p].size();
    if(p==g){
        return t[m[p]].task;
    }
    pushdown(p);
    if(t[m[p]].l<=m[g]&&m[g]<=t[m[p]].r){
        for(int i=0;i<len;i++){
            int ptr=v[p][i];
            if(ptr==g){
                return ask(v[p][i],g);
            }
            else if(t[m[ptr]].l<=m[g]&&m[g]<=t[m[ptr]].r){
                return ask(v[p][i],g);
            }
        }
    }
}
void change(int p,int g,int val){
    int len=v[p].size();
    if(p==g){
        t[m[p]].task=val;
        t[m[p]].lazy=val;
        return;
    }
    pushdown(p);
    if(t[m[p]].l<=m[g]&&m[g]<=t[m[p]].r){
        int len=v[p].size();
        for(int i=0;i<len;i++){
            int ptr=v[p][i];
            if(v[p][i]==g){
                change(v[p][i],g,val);
                return;
            }
            else if(t[m[ptr]].l<=m[g]&&m[g]<=t[m[ptr]].r){
                change(ptr,g,val);
                return;
            }
        }
    }
}
int main()
{
    int _,tot=1;
    scanf("%d",&_);
    while(_--){
        int n;
        scanf("%d",&n);
        cnt=1;
        m.clear();
        memset(in,0,sizeof(in));

        for(int i=1;i<n;i++){
            int s,f;
            scanf("%d%d",&s,&f);        
            v[f].push_back(s);
            in[s]++;
        }
        int head=0;
        for(int i=1;i<=n;i++){
            if(in[i]==0){
                head=i;
                break;
            }
        }
        m[head]=cnt++;
        build(head);
        int t;
        scanf("%d",&t);
        char s;
        printf("Case #%d:\n",tot++);
        for(int i=1;i<=t;i++){
            scanf("\n %c",&s);
            if(s=='C'){
                int q;
                scanf("%d",&q);
                printf("%d\n",ask(head,q));
            }
            else if(s=='T'){
                int e,ex;
                scanf("%d%d",&e,&ex);
                change(head,e,ex);
            }
        }
        for(int i=1;i<=n;i++)v[i].clear();
    }
}