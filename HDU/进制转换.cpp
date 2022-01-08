#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;
vector<char> v;
string ss;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long int n=0,r,num=0,cnt=0;
    while(cin>>num>>r)
    {
        if(num>=0)
        {
            while(num>0)
            {
                cnt=num%r;
                if(cnt==10)v.push_back('A');
                else if(cnt==11)v.push_back('B');
                else if(cnt==12)v.push_back('C');
                else if(cnt==13)v.push_back('D');
                else if(cnt==14)v.push_back('E');
                else if(cnt==15)v.push_back('F');
                else v.push_back(char(cnt+48));
                num=num/r;
            }
            for(int i=v.size()-1;i>=0;i--)cout<<v[i];
            cout<<endl;//cout<<endl;
            v.clear();//for(int i=0;i<v.size();i++)v[i]=0;
        }
        else
        {
            num=-num;
            while(num>0)
            {
                cnt=num%r;
                num=num/r;
                if(cnt==10)v.push_back('A');
                else if(cnt==11)v.push_back('B');
                else if(cnt==12)v.push_back('C');
                else if(cnt==13)v.push_back('D');
                else if(cnt==14)v.push_back('E');
                else if(cnt==15)v.push_back('F');
                else v.push_back(char(cnt+48));

            }
            cout<<'-';
            for(int i=v.size()-1;i>=0;i--)cout<<v[i];
            cout<<endl;
            v.clear();//for(int i=0;i<v.size();i++)v[i]=0;
        }
    }
}
