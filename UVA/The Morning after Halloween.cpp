#include<cstdio>
#include<cctype>
#include<vector>

using namespace std;

vector<int> box[150];

int main()
{
    int n,m,k;
    getchar();
    char a;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
           a=getchar();
           if(a!='#')
           {
               if(islower(a))
                   box[cnt++].push_back(a-'a');
               else if(isupper(a))
                   box[cnt++].push_back(a-'A');
               else box[cnt++].push_back()
           }
        }
    }

}
