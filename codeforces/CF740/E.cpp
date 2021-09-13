		/*
			1.找到最大偶数位数n，转到1（答案要求小于5*n/2）
			2.再转到n-1的前一位（满足奇数位的条件，因为n-1为偶数）
			3。反转i到1。
			4.找到最大值的位置，再次反转到1的位置
			5.1和n反转
		*/
#include<bits/stdc++.h>
using namespace std;
const int N=2023;
int a[N];
vector<int> ans;
int n;
int findx(int x){
	for(int i=1;i<=n;i++){
		if(a[i]==x)return i;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		bool ok=1;
		for(int i=1;i<=n;i++){
			if(a[i]%2!=i%2){
				//cout<<a[i]<<" "<<i<<endl; 
				ok=0;
				break;
			}
		}
		if(!ok){
			cout<<-1<<endl;
			continue;
		}
		for(int i=n-1;i>=1;i-=2){
			int j=findx(i+1);
			ans.push_back(j);
			reverse(a+1,a+1+j);
			
			int p=findx(i);
			ans.push_back(p-1);
			reverse(a+1,a+p);
			ans.push_back(i+1);
			reverse(a+1,a+2+i);
			
			j=findx(i+1);
			ans.push_back(j);
			reverse(a+1,a+1+j);
			
			ans.push_back(i+1);
			reverse(a+1,a+2+i);
		}
		int len=ans.size();
		cout<<len<<endl;
		for(int i=0;i<len;i++){
			cout<<ans[i]<<" ";
		}
		if(len!=0)cout<<endl;
		ans.clear();
	}	
}