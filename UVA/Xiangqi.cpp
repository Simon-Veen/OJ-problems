#include <cstdio>
#include <iostream>

using namespace std;

int bgx,bgy;
char board[15][15];
bool notice[15][15];
void board_clear()
{
    for(int i=1;i<=10;i++)
        for(int j=1;j<=9;j++)
            board[i][j]=0;
}
void notice_clear()
{
    for(int i=1;i<=10;i++)
        for(int j=1;j<=9;j++)
            notice[i][j]=0;
}
void General(int x,int y)
{
    for(int i=1;i<=10;i++)
        if(board[i][y]!=0 && board[i][y]!='b' && board[i][y]!='G') return;            //0即是NULL
    for(int i=1;i<=3;i++) notice[i][y]=1;     //上三排全占

}
void Chariot(int x,int y)
{
    //以车为原点向上下两侧延伸
    for(int i=x+1;i<=10;i++)
    {
        if(board[i][y]==0) notice[i][y]=1;
        else if(board[i][y]=='b'){notice[i][y]=1;break;}
        else break;
    }
    //*/
    for(int i=x-1;i>=1;i--)
    {
        if(board[i][y]==0) notice[i][y]=1;
        else if(board[i][y]=='b'){notice[i][y]=1;break;}
        else break;
    }

    //以车为原点向左右两侧延伸
    for(int i=y+1;i<=9;i++)
    {
        if(board[x][i]==0)notice[x][i]=1;
        else if(board[x][i]=='b'){notice[x][i]=1;break;}
        else break;
    }
    for(int i=y-1;i>=1;i--)
    {
        if(board[x][i]==0)notice[x][i]=1;
        else if(board[x][i]=='b'){notice[x][i]=1;break;}
        else break;
    }
}
void Cannon(int x,int y)
{
    //上下左右是否有棋子
    bool bx=0,bs=0,bz=0,by=0;
    int px=0,ps=0,pz=0,py=0;
    for(int i=x+1;i<=10;i++)
        if(board[i][y]!='b' && board[i][y]!=0){bx=1;px=i;break;}
    for(int i=x-1;i>=1;i--)
        if(board[i][y]!='b' && board[i][y]!=0){bs=1;ps=i;break;}
    for(int i=y+1;i<=9;i++)
        if(board[x][i]!='b' && board[x][i]!=0){by=1;py=i;break;}
    for(int i=y-1;i>=1;i--)
        if(board[x][i]!='b' && board[x][i]!=0){bz=1;pz=i;break;}
    //在有棋子的基础上进行标记，上下左右
    if(bx)
    {
        for(int i=px+1;i<=10;i++)
        {
            if(board[i][y]!=0 && board[i][y]!='b'){notice[i][y]=1;break;}
            else notice[i][y]=1;
        }
    }
    if(bs)
    {
        for(int i=ps-1;i>=1;i--)
        {
            if(board[i][y]!=0 && board[i][y]!='b'){notice[i][y]=1;break;}
            else notice[i][y]=1;
        }
    }
    if(bz)
    {
        for(int i=pz-1;i>=1;i--)
        {
            if(board[i][y]!=0 && board[i][y]!='b'){notice[x][i]=1;break;}
            else notice[x][i]=1;
        }
    }
    if(by)
    {
        for(int i=py+1;i<=9;i++)
        {
            if(board[x][i]!=0 && board[x][i]!='b'){notice[x][i]=1;break;}
            else notice[x][i]=1;
        }
    }
}
void Horse(int x,int y)
{
    //进行蹩马腿判断
    bool bs=1,bx=1,bz=1,by=1;
    if(board[x+1][y]!=0)bx=0;
    if(board[x-1][y]!=0)bs=0;
    if(board[x][y+1]!=0)by=0;
    if(board[x][y-1]!=0)bz=0;
    //8向跳马
    if(bx && x+2<=10)
    {
        if(y+1<=9)notice[x+2][y+1]=1;
        if(y-1>=1)notice[x+2][y-1]=1;
    }
    if(bz && y-2>=1)
    {
        if(x+1<=9)notice[x+1][y-2]=1;
        if(x-1>=1)notice[x-1][y-2]=1;
    }
    if(bs && x-2>=1)
    {
        if(y+1<=9)notice[x-2][y+1]=1;
        if(y-1>=1)notice[x-2][y-1]=1;
    }
    if(by && y+2<=9)
    {
        if(x+1<=9)notice[x+1][y+2]=1;
        if(x-1>=1)notice[x-1][y+2]=1;
    }
}
void board_write()
{
    //board_clear();
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(board[i][j]=='G')General(i,j);
            else if(board[i][j]=='R')Chariot(i,j);
            else if(board[i][j]=='H')Horse(i,j);
            else if(board[i][j]=='C')Cannon(i,j);
        }
    }
    /*
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=9;j++)
            cout<<notice[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
    */
}
bool mov(int x,int y)
{
    //依次在可行方向上进行预走
    char m=0;
    if(x+1<=3)
    {
        m=board[x+1][y];
        board[x+1][y]='b';
        board[x][y]=0;
        notice_clear();
        board_write();
        if(!notice[x+1][y]) return true;
    }
    //还原
    board[x+1][y]=m;
    board[x][y]='b';
    notice_clear();
    board_write();
    if(x-1>=1)
    {
        m=board[x-1][y];
        board[x-1][y]='b';
        board[x][y]=0;
        notice_clear();
        board_write();
        if(!notice[x-1][y])return true;
    }
    board[x-1][y]=m;
    board[x][y]='b';
    notice_clear();
    board_write();
    if(y+1<=6)
    {
        m=board[x][y+1];
        board[x][y+1]='b';
        board[x][y]=0;
        notice_clear();
        board_write();
        if(!notice[x][y+1])return true;
        board[x][y+1]=m;
    }
    board[x-1][y]=m;
    board[x][y]='b';
    notice_clear();
    board_write();
    if(y-1>=4)
    {
        m=board[x][y-1];
        board[x][y-1]='b';
        board[x][y]=0;
        notice_clear();
        board_write();
        if(!notice[x][y-1])return true;
    }
    board[x][y-1]=m;
    board[x][y]='b';
    notice_clear();
    board_write();
    return false;
    //若都不行则f，否则t
}
int main()
{
    int n=0,wx=0,wy=0;
    char c=0;
    while((scanf("%d%d%d",&n,&bgx,&bgy))==3 && n!=0)
    {
        board_clear();  //洗盘
        notice_clear();
        //构建棋盘
        board[bgx][bgy]='b';
        for(int i=1;i<=n;i++)
        {
            //scanf("%c%d%d",&c,&wx,&wy)  //连续输入时不要用scanf("%c",&c);因为可以读到空格
            cin>>c>>wx>>wy;
            board[wx][wy]=c;
        }

        board_write();//遍历判断棋盘
        //判断黑将还有无其他走法
        /*
        for(int i=1;i<=10;i++)
        {
            for(int j=1;j<=9;j++)
                cout<<notice[i][j]<<' ';
            cout<<endl;
        }
        */
        if(!mov(bgx,bgy)) printf("YES\n");
        else printf("NO\n");
    }
}
