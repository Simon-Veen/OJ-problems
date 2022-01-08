#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;


const int MAXN=50;

int a[MAXN],b[MAXN];
int num=1;


int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);

    while(scanf("%d",&a[num])!=EOF){

        while(getchar()!='\n'){
            num++;
            scanf("%d",&a[num]);
        }
        for(int i=1;i<=num;i++) {
            b[i]=a[i];
            printf("%d",a[i]);
            if(i!=num)printf(" ");
        }
        printf("\n");
        sort(b+1,b+1+num);
        for(int i=num;i>=1;i--){
            if(a[i]!=b[i]){  //不在排好序的位置
                for(int j=i-1;j>=1;j--){
                    if(a[j]==b[i]){
                        if(j!=1){
                            printf("%d ",num-j+1);
                            for(int k=1;k<=j/2;k++) swap(a[k],a[j+1-k]);
                        }
                        for(int j=1;j<=i/2;j++) swap(a[j],a[i+1-j]);
                        printf("%d ",num-i+1);
                        break;
                    }
                }

            }
        }
        printf("0\n");
        memset(a,0,sizeof(a));
        num=1;
    }
}
