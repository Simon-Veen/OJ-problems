#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN],b[MAXN],z[MAXN];
int LIS(int len){
    for(int i=1;i<=len;i++)b[i]=MAXN,z[i]=0;
    for(int i=1;i<len;i++){
        *upper_bound(b+1,b+len,a[i])=a[i];
    }
    return lower_bound(b+1,b+len,MAXN)-b-1;
}
int main()
{
    int x,cnt=1,sum=0;
    while(scanf("%d",&a[cnt++])!=EOF);cnt--;
    for(int i=1;i<=cnt/2;i++)swap(a[i],a[cnt-i]);
    int ans=LIS(cnt);
    z[1]=a[1];
    for(int i=2;i<cnt;i++){
        *lower_bound(z+1,z+cnt,a[i],greater<int>())=a[i];
    }
    int e=1;
    while(z[e])e++;
    printf("%d\n%d",ans,e-1);
}
