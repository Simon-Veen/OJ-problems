#include<cstdio>

int n,h,l,w;
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    while(scanf("%d",&n)!=EOF&&n)
    {
        char a='A';
        printf("2 %d %d\n",n,n);
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(a>=65&&a<=90){
                    printf("%c",a);
                    continue;
                }
                if(a>=97&&a<=122){
                    printf("%c",a);
                    continue;
                }
                if(a==91){
                        a=97;
                    printf("%c",a);
                }
                else if(a==123){
                        a=65;
                    printf("%c",a);
                }
            }
            printf("\n");
            a++;
        }
        printf("\n");
        a='A';
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(a>=65&&a<=90){
                    printf("%c",a++);
                    continue;
                }
                if(a>=97&&a<=122){
                    printf("%c",a++);
                    continue;
                }
                if(a==91){
                    a=97;
                    printf("%c",a++);
                }
                else if(a==123){
                    a=65;
                    printf("%c",a++);
                }
            }
            a='A';
            printf("\n");
        }
    }
}
