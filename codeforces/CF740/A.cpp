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
