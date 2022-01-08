#include <iostream>
#include <string>

using namespace std;
string ss;
int months[7]={1,3,5,7,8,10,12},tm[4]={4,6,9,11};
int year,month,day;
int main()
{
    int n=1000,pt,cnt;
    while(cin>>ss)
    {
        cnt=0;pt=7;
        year=(int(ss[0])-48)*1000+(int(ss[1])-48)*100+(int(ss[2])-48)*10+(int(ss[3])-48);
        if(ss[6]!='/')
        {
            month=(int(ss[5])-48)*10+int(ss[6])-48;
            pt=8;
        }
        else month=int(ss[5]-48);
        if(pt+1==ss.size())   //只有1位
            day=(int(ss[pt])-48);
        else day=int(ss[pt]-48)*10+int(ss[pt+1])-48;

        if(year%400==0 && month>2) cnt+=29;
        else if(year%400!=0 && month>2) cnt+=28;
        for(int i=0;i<7;i++)
        {
            if(months[i]<month)
            {
                //cout<<months[i]<<' ';
                cnt+=31;continue;
            }
            break;
        }
        for(int i=0;i<4;i++)
        {
            if(tm[i]<month)
            {
                cnt+=30;continue;
            }
            break;
        }
        cnt+=day;
        //cout<<"day"<<day<<' ';
        cout<<cnt<<endl;
    }

}
