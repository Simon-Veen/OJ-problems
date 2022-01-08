#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    bool k=0;
    double a,b=3.1415927,s;
    while(cin>>a)
    {
        s=(4*b*a*a*a)/3;
        printf("%.3lf\n",s);
    }
}
