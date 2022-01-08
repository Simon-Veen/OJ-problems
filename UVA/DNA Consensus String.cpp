#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
char op[55][1005];
int c[1005][4];
int num,m,n,lab;
string f;

void clr_op()
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            op[i][j]='0';
}
void clr_c()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<4;j++)
            c[i][j]=0;
}
int main()
{
    scanf("%d",&num);
    for(int p=1;p<=num;p++)
    {
        scanf("%d%d",&m,&n);
        clr_op();clr_c();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                    cin>>op[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
               if(op[j][i]=='A')c[i][0]++;
               if(op[j][i]=='C')c[i][1]++;
               if(op[j][i]=='G')c[i][2]++;
               if(op[j][i]=='T')c[i][3]++;
            }
        int w=0,sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<4;j++)
                if(c[i][j]>lab) {lab=c[i][j];w=j;}
            if(w==0)f+='A';
            if(w==1)f+='C';
            if(w==2)f+='G';
            if(w==3)f+='T';
            lab=0;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(op[j][i]!=f[i])sum++;

        cout<<f<<endl<<sum<<endl;
        f.clear();
    }
}
