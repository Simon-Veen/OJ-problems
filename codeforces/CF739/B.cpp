/*

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a<b)swap(a,b);
        int op=b-1,cen=a-op;
        int big=2*cen-2;
        if(big%2==0&&a<=big&&c<=big){
            if(c>=cen){
                cout<<c-cen+1<<endl;
            }
            else {
                cout<<c-1+cen<<endl;
            }
        }
        else cout<<"-1"<<endl;
    }
}
*/
