#include<iostream>
#include<string>

using namespace std;
string a,b,c;
bool pan(char k,char j)
{
    if((c[0]==k&&c[5]==j)||(c[0]==j&&c[5]==k))
    {
        c[0]=c[5]='1';      
        return true;
    }
    if((c[1]==k&&c[4]==j)||(c[1]==j&&c[4]==k))
    {
        c[1]=c[4]='1';
        return true;
    }
    if((c[2]==k&&c[3]==j)||(c[2]==j&&c[3]==k))
    {
        c[2]=c[3]='1';  
        return true;
    }
    return false;
}
int main()
{

    while(cin>>a)
    {
        for(int i=0;i<=5;i++) b+=a[i];
        for(int i=6;i<a.size();i++)c+=a[i];
			if(pan(b[0],b[5]))
	            if(pan(b[1],b[4]))
	                if(pan(b[2],b[3]))
	                {  	
	                    cout<<"TRUE"<<endl;
	                    a.clear();b.clear();c.clear();
	                    continue;
	                }
        cout<<"FALSE"<<endl;
        a.clear();b.clear();c.clear(); 
    }
}