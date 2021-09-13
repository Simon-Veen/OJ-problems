#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=1e5+10;
struct node{
    ull st,ed;
    bool operator < (const node& k){
        if(st==k.st){
            return ed>k.ed;
        }
        return st<k.st;
    }
}s[N];
int n;
bool judge(ull k){
    ull all=k;
    for(int i=1;i<=n;i++){
        if(all>=s[i].st){
            all+=s[i].ed;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int p;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p;
            s[i].ed=p;
            int x,mx=0;
            for(int j=1;j<=p;j++){
                cin>>x;
                if(mx<x-j+2)mx=x-j+2;
            }
            s[i].st=mx;
        }
        sort(s+1,s+1+n);
        int l=1,r=1e9+10,mid;
        while(l<=r){
            mid=l+r>>1;
            if(judge(mid)){
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<l<<endl;
    }
}