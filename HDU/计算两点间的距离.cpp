#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    float a,b,c,d;
    while(scanf("%f%f%f%f",&a,&b,&c,&d)==4)
    {
        float x,y,j;
        x=(a-c)*(a-c);
        y=(b-d)*(b-d);
        j=sqrt(x+y);
        printf("%.2f\n",j);
    }


}
