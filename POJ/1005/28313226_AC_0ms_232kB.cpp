#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double p=3.14159265;
int main()
{
    int n,cnt;
    double x,y,d,r;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        d=sqrt(x*x+y*y);
        cnt=1;
        while(1)
        {
            r=10*sqrt(cnt/p);
            if(r>=d)break;
            cnt++;
        }
        cout<<"Property "<<i<<": This property will begin eroding in year "<<cnt<<"."<<endl;
    }
    cout<<"END OF OUTPUT.";
}