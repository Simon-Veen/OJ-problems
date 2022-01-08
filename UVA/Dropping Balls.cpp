#include<cstdio>

int main()
{


    int t;
    scanf("%d",&t);
    while(t--){
        int d,l;
        scanf("%d%d",&d,&l);
        long long int sum=1,lv=1;
        while(lv<d){
            if(l%2==0){
                sum=sum*2+1;
                l=l/2;
            }
            else{
                sum=sum*2;
                l=(l+1)/2;
            }
            lv++;
        }
        printf("%lld\n",sum);
    }
    scanf("%d",&t);

}
