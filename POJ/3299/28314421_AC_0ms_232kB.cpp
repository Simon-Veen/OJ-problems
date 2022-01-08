#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

void H(double t,double d)
{
    double k,h;
    k=6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
    h=(0.5555)*(k-10.0);

    printf("T %.1lf D %.1lf H %.1lf",t,d,h+t);
}
int main()
{
    double t,d,h;
    char tt,dd;
    bool a=0;
    while(cin>>tt>>t>>dd>>d)
    {
        if(a)cout<<endl;
        a=1;
        if(tt=='T'&&dd=='D')H(t,d);
        else if(tt=='D'&&dd=='T')H(d,t);
        else if(tt=='T'&&dd=='H')
        {
            double k=1/(1/273.16-(log(((d-t)/0.5555+10.0)/6.11))/5417.7530)-273.16;
            printf("T %.1lf D %.1lf H %.1lf",t,k,d);
        }
        else if(tt=='H'&&dd=='T')
        {
           double k=1/(1/273.16-(log(((t-d)/0.5555+10.0)/6.11))/5417.7530)-273.16;
           printf("T %.1lf D %.1lf H %.1lf",d,k,t); 
        }
        else if(tt=='H'&&dd=='D')
        {
            double k=6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
            h=(0.5555)*(k-10.0);
            printf("T %.1lf D %.1lf H %.1lf",t-h,d,t); 
        }
        else if(tt=='D'&&dd=='H')
        {
            double k=6.11*exp(5417.7530*((1/273.16)-(1/(t+273.16))));
            h=(0.5555)*(k-10.0);
            printf("T %.1lf D %.1lf H %.1lf",d-h,t,d);
        }
    }
}
