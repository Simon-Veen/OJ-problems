#include <cstdio>
#include <string>
using namespace std;
int num[10];
string zm;
int main()
{
    int n,sz,j,p;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&sz);
        for(int i=1;i<=sz;i++)
        {
            j=i;
            while(j)
            {
                p=j%10;
                zm+=char(p+48);
                j/=10;
            }
        }
        for(int i=0;i<zm.size();i++)num[int(zm[i])-48]++;
        for(int i=0;i<10;i++)
        {
            if(i==9)printf("%d\n",num[i]);
            else printf("%d ",num[i]);
        }
        for(int i=0;i<10;i++)num[i]=0;
        zm.clear();
    }
}
