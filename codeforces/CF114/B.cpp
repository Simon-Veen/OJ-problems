#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--){
		long long a[3],m;
		int big,me,sm;
		cin>>a[0]>>a[1]>>a[2]>>m;
		sort(a,a+3);
		for(int i=2;i>=0;i--){
			if(m>=a[i]-1){
				m-=(a[i]-1);
				a[i]=0;
				if(m==0)break;
			}
			else{
				a[i]-=(m+1);
				m=0;
				break;
			}
		}
		sort(a,a+3);
		if(m==0&&(a[2]-1<=a[1]+a[0]||a[2]==2)){
			m=0;
		}
		else m=1;
		
		if(m>0)cout<<"NO"<<endl;
		if(m==0)cout<<"YES"<<endl;
	}	
	
}