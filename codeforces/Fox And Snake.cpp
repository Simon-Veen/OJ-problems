#include <iostream>

using namespace std;

char box[55][55];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i+=2)
        for(int j=1;j<=m;j++)
            box[i][j]='#';
    bool k=1;
    for(int i=2;i<=n;i+=2)
    {
        k=!k;
        if(k==0)
        {
            for(int j=1;j<m;j++) box[i][j]='.';
            box[i][m]='#';
        }
        else
        {
            for(int j=2;j<=m;j++)box[i][j]='.';
            box[i][1]='#';
        }
    }
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
            cout<<box[i][j];
        cout<<endl;
    }
}
