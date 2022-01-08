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

/*

#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int a[N];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long ans=0;
        bool ok=0;
        for(int i=1;i<n;i++){
            if(a[i]>a[i+1]){
                ok=1;
                break;
            }
        }
        while(ok){

            ans++;
            int p;
            if(ans%2==1)p=1;
            else p=2;
            for(int i=p;i<n;i+=2){
                if(a[i]>a[i+1]){
                    swap(a[i],a[i+1]);
                }
            }
            ok=0;
            for(int i=1;i<n;i++){
                if(a[i]>a[i+1]){
                    ok=1;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }

}
*/
