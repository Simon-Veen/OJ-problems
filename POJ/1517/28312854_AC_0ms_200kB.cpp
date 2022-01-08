#include<iostream>

#include<cstdio>

using namespace std;
int ans;
double jc(int i)
{
    double d=1;
    for(int p=1;p<=i;p++)d*=p;
    return 1/d;
}
int main()
{
    double k=2.5;
    cout<<"n e"<<endl;
    cout<<"- -----------"<<endl;
    cout<<"0 1"<<endl;
    cout<<"1 2"<<endl;
    cout<<"2 2.5"<<endl;
    for(int i=3;i<=9;i++)
    {
        k+=jc(i);
        printf("%d %.9lf\n",i,k);
    }
}