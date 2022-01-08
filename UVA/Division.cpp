#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> ans,a;
bool zero(int a,int b)
{
    int z[10];
    memset(z,0,sizeof(z));
    int p;
    int ptr=0;
    if(a<=9999)z[0]++;
    if(b<=9999)z[0]++;
    //int prt=0
    while(a)
    {
        p=a%10;  //21
        z[p]+=1;
        a=a/10;
    }
    while(b)
    {
        p=b%10;
        z[p]+=1;
        b=b/10;
    }
    for(int i=0;i<=9;i++)
    {   
        if(!z[i]||z[i]>1)return false;
    }
    return true;
}
int main()
{
    int n,k=0,c=0,j;
    while(1)
    {
        cin>>n;
        ans.clear();
        a.clear();
        c=0;
        if(n==0)break;
            for(int i=1234;i<=50000;i++)
            {
                    j=i*n;
                    if(zero(i,j))
                    {
                        ans.push_back(j);
                        a.push_back(i);
                    }
            }
        if(k)cout<<"\n";
        k=1;
        if(a.size()!=0)
        {
            for(int i=0;i<a.size();i++)
            {
                if(c)cout<<endl;
                if(ans[i]<=9999)putchar('0');
                cout<<ans[i]<<" / ";
                if(a[i]<=9999)putchar('0');
                cout<<a[i]<<" = "<<n;
                c=1;
            }
        }
        else 
        {
            cout<<"There are no solutions for "<<n<<".";
        }
        cout<<endl;
    }
}