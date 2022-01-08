#include<iostream>
using namespace std;
char sz[5];
bool k=0;
int main()
{
    while(cin>>sz)
    {
     //   if(k)cout<<endl;
        for(int i=0;i<3;i++)
            for(int j=i+1;j<3;j++)
                if(int(sz[i]>int(sz[j])))swap(sz[i],sz[j]);
        for(int i=0;i<3;i++)
        {
            cout<<sz[i];
            if(i!=2)cout<<' ';
        }
        cout<<endl;
    }
}
