/*

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        int q=sqrt(k);
        if(q*q<k)q++;
        else if(q*q==k){
            cout<<q<<" "<<"1"<<endl;
            continue;
        }
        int del=q*q-k;
        if(del<q){
            cout<<q<<" "<<1+del<<endl;
        }
        else{
            int top=(q-1)*(q-1)+1;

            cout<<1+k-top<<" "<<q<<endl;
        }
    }
}
*/
