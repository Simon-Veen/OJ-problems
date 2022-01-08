#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=5e4+10;

int k[MAXN];
char s[2];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        char x;
        int w,cnt=0;
        set<int> st;
        for(int i=1;i<=m;i++){
            scanf("%s",s);
            if(s[0]=='D'){
                scanf("%d",&w);
                k[++cnt]=w;
                st.insert(w);
            }
            else if(s[0]=='R'){
                st.erase(k[cnt--]);
            }
            else if(s[0]=='Q'){
                scanf("%d",&w);
                set<int>::iterator e=st.lower_bound(w);
                int r=(e==st.end()?n+1:*e);
                int l=(e==st.begin()?0:*(--e));
                if(r==w) printf("0\n");
                else printf("%d\n",r-l-1);
            }
        }
    }
}
/*
#include<cstdio>
#include<stack>
#include<iostream>


using namespace std;
#define lson p<<1
#define rson p<<1|1
const int MAXN=5e5+19;
struct sege{
    int l,r,len;
    bool bm;
    bool lazy;
}t[MAXN<<2];
stack<int> st;
void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r){
        t[p].len=1;
        t[p].bm=0;
        t[p].lazy=0;
        return;
    }
    int mid=l+r>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    t[p].len=t[lson].len+t[rson].len;
    t[p].bm=0;t[p].lazy=0;
}
void change(int p,int x,int v){
    if(t[p].l==t[p].r&&t[p].l==x){
        if(v==1)t[p].bm=0;
        else t[p].bm=1;
        t[p].len=0;
        return;
    }
    int mid=t[p].l+t[p].r>>1;
    if(x<=mid){
        change(lson,x,v);
    }
    if(x>mid){
        change(rson,x,v);
    }
    if(t[rson].bm||t[lson].bm)t[p].bm=1;
    else t[p].bm=0;
}
void pushdown(int p){
    if(t[p].lazy){
        t[lson].len=t[p].len;
        t[rson].len=t[p].len;
        t[lson].lazy=1;
        t[rson].lazy=1;
        t[p].lazy=0;
    }

}
int ask(int p,int x){   
    if(t[p].l==t[p].r&&t[p].l==x){
        return t[p].len;
    }
    pushdown(p);
    int mid=t[p].l+t[p].r>>1;
    if(x<=mid){
        return ask(lson,x);    
    }
    if(x>mid){
        return ask(rson,x);
    }
}
int lfind(int p,int l,int r){
    if(l<=t[p].l&&t[p].r<=r){
        if(t[p].bm){
            if(t[p].l==t[p].r)return t[p].l;
            if(t[rson].bm)return lfind(rson,l,r);
            else if(t[lson].bm)return lfind(lson,l,r);
        }
        return 0;
    }
    int pos=0;
    int mid=t[p].l+t[p].r>>1;
    if(t[p].r>mid&&t[rson].bm){
        pos=lfind(rson,l,r);
    }
    if(pos)return pos;
    if(t[p].l<=mid&&t[lson].bm){
        pos=lfind(lson,l,r);
    }
    return pos;
}
int rfind(int p,int l,int r){
    if(l<=t[p].l&&t[p].r<=r){
        if(t[p].bm){
            if(t[p].l==t[p].r)return t[p].l;
            if(t[lson].bm) return rfind(lson,l,r);
            else if(t[rson].bm)return rfind(rson,l,r);
        }
        return 0;
    }
    int mid=t[p].l+t[p].r>>1;
    int pos=0;
    if(l<=mid&&t[lson].bm){
        pos=rfind(lson,l,r);
    }
    if(pos)return pos;
    if(r>mid&&t[rson].bm){
        pos=rfind(rson,l,r);
    }
    return pos;
}
void super_change(int p,int l,int r,int v){
    if(l<=t[p].l&&t[p].r<=r){
        if(l==r)t[p].len=v;
        else{
            t[p].len=v;
            t[p].lazy=1;
        }
        return;
    }
    pushdown(p);
    int mid=t[p].l+t[p].r>>1;
    if(l<=mid)super_change(lson,l,r,v);
    if(r>mid)super_change(rson,l,r,v);
}
bool find(int p,int s){
    if(t[p].l==t[p].r&&t[p].l==s){
        if(t[p].bm==1)return true;
        else return false;
    }
    int mid=t[p].l+t[p].r>>1;
    if(s<=mid){
        return find(lson,s);
    }
    if(s>mid){
        return find(rson,s);
    }
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        char c;
        int d;
        build(1,1,n);
        for(int i=1;i<=m;i++){
            scanf("\n %c",&c);
            if(c=='D'){
                scanf("%d",&d);
                if(find(1,d)){
                    continue;
                }
                change(1,d,0);
                int ll=lfind(1,1,d-1);
                int rr=rfind(1,d+1,n);
                if(rr==0)rr=n+1;
                super_change(1,ll+1,d-1,d-1-ll);
                super_change(1,d+1,rr-1,rr-1-d);
                st.push(d);
            }
            else if(c=='Q'){
                scanf("%d",&d);
                printf("%d\n",ask(1,d));
            }
            else if(c=='R'){
                if(st.size()==0)continue;
                int dx=st.top();
                st.pop();
                change(1,dx,1);
                int ll=lfind(1,1,dx-1);
                int rr=rfind(1,dx+1,n);
                if(rr==0)rr=n+1;
                super_change(1,ll+1,rr-1,rr-1-ll);
            }
        }
    }
}
*/