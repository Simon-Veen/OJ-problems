#include<bits/stdc++.h>
using namespace std;

const int N=2e4+10;
char a[N];
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		scanf("%s",a+1);
		bool ok=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='0'){
				if(i+n/2<=n&&i+1<=i+n/2){
					cout<<i+1<<" "<<i+n/2<<" "<<i<<" "<<i+n/2<<endl;
					ok=1;
					break;
				}
				if(i-n/2>=1&&i-n/2<=i-1){
					cout<<i-n/2<<" "<<i<<" "<<i-n/2<<" "<<i-1<<endl;
					ok=1;
					break;
				}
			}
		}
		if(ok)continue;
		cout<<1<<" "<<n-n%2<<" "<<1<<" "<<n/2<<endl;
	}
}