#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    bool k=0;
    double a,b,s;
    while(cin>>a)
    {
        if(a<0)printf("%.2lf\n",-a);
        else printf("%.2lf\n",a);
    }
}
