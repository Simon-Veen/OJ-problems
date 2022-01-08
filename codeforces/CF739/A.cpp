#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int a[N];
int main()
{
    int cnt=1;
    for(int i=1;i<=10000;i++){
        if(i%3!=0&&i%10!=3){
            a[cnt++]=i;
        }
    }
    int t;
    scanf("%d",&t);

    while(t--){
        int k;
        cin>>k;
        printf("%d\n",a[k]);
    }

}
