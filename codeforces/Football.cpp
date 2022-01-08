#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[105];
int main()
{
    cin>>a;
    //判1
    int cnt=1;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='1')
        {
            cnt=1;
            for(int j=i+1;j<strlen(a);j++)
            {
                if(a[j]=='1')cnt++;
                if(cnt<7 && a[j]!='1')break;
                if(cnt>=7){cout<<"YES";return 0;}
            }
        }
    }
    //判0
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='0')
        {
            cnt=1;
            for(int j=i+1;j<strlen(a);j++)
            {
                if(a[j]=='0')cnt++;
                if(cnt<7 && a[j]!='0') break;
                if(cnt>=7){cout<<"YES";return 0;}
            }
        }
    }
    cout<<"NO";
}
