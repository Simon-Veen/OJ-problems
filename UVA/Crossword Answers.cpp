#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int h,l,cnt,sum=1;
char box[15][15];
int p[15][15];         //计数数组
bool dw[15][15];        //向下输出标记数组
void clr_p()
{
    for(int i=1;i<=h;i++)
        for(int j=1;j<=l;j++)
            {p[i][j]=0;box[i][j]='0';dw[i][j]=0;}
}
bool judge(int hh,int ll)
{
    for(int i=1;i<=hh;i++)
        for(int j=1;j<=ll;j++)
            if(!dw[i][j])return true;
    return false;
}
int main()
{
	while(scanf("%d",&h)&& h!=0)
	{
	    scanf("%d",&l);
        if(sum>1)printf("\n");
		//初始化
		cnt=1;
        clr_p();
		//输入
		for(int i=1;i<=h;i++)
			for(int j=1;j<=l;j++)
				cin>>box[i][j];//scanf("%c",box[i][j]);
		//标记
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=l;j++)
			{
				if(box[i-1][j]=='*' || box[i][j-1]=='*')
                {
					if(box[i][j]!='*')
                        p[i][j]=cnt++;
                }
				else if(i-1<1 || j-1<1)
				{
                    if(box[i][j]!='*')
                        p[i][j]=cnt++;
				}
			}
		}

		printf("puzzle #%d:",sum++);
		//横向
		printf("\nAcross");
		bool swc=1;
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=l;j++)
			{
				if(swc&&box[i][j]!='*'){printf("\n%3d.",p[i][j]);swc=0;}
				if(box[i][j]!='*')  printf("%c",box[i][j]);
                if(box[i][j]=='*'||j==l)swc=1;
			}
		}
		printf("\nDown\n");
        //bool swc=1;
        int x=1,y=1,t=l+1;
        while(judge(h,l))
        {
            for(int i=1;i<=h;i++)
            {
                for(int j=1;j<=l;j++)
                {
                    swc=1;
                    if(box[i][j]=='*')dw[i][j]=1;
                    if(!dw[i][j]&& p[i][j] && swc)
                    {
                        printf("%3d.",p[i][j]);
                        swc=0;
                        for(int k=i;k<=h;k++)
                        {
                            if(!dw[k][j]&& box[k][j]!='*')
                            {
                                printf("%c",box[k][j]);
                                dw[k][j]=1;
                            }
                            if(box[k][j]=='*'){;dw[k][j]=1;break;}
                        }
                        printf("\n");
                    }
                }
            }
        }
        //printf("\n");
	}
	//if(!h)printf("\n");
}
