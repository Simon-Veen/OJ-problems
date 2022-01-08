#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

double f(double x,double a,double b,double c,double d){
    return a*x*x*x+b*x*x+c*x+d;
}

double bsearch(double x,double y,double a,double b,double c,double d){
    while(abs(x-y)>0.0001){
        double mid=(x+y)/2;
        if(f(mid,a,b,c,d)>0)y=mid;
        else x=mid;
    }
    return x;
}
int main()
{
    double a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    for(double i=-100;i<=100;i+=0.05){
        if(i+0.005<=100&&f(i,a,b,c,d)*f(i+0.005,a,b,c,d)<=0){
            printf("%.2lf ",bsearch(i,i+0.005,a,b,c,d));
        }
    }
}
