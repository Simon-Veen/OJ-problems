#include <cstdio>
#include <cstring>
char ss[1000];                        //只有ss字符数组定义为全局变量，为pro和main函数共用
double pro(int j,int len)
{
    int p=j+1,s=1;                      //这里的p是字符之后的位置
    double cnt=0;
    if(int(ss[p])>57||p==len)return 1;   //若字符下一位是字母或者已经到达边界，则个数为1； 这里判断是否为字母可用isalpha函数，看起来更舒服。

    while(int(ss[p])<=57&&p<len)p+=1;    //记录在不超出范围时字符后数字位置，遇到下一个字母就停止

    for(int i=p-1;int(ss[i])<=57&&i>=1;i--)  //从下一个字母倒序，且第一个字符一定是字母
    {
        cnt+=(int(ss[i])-48)*s;                 //将字母转化为int型并且进行位数乘法。
        s*=10;
    }
    return cnt;        //返回一个字母之后的所有数字
}
int main()
{
    int n;
    double ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)            //输入的时候可以用while(n--)从[1,n]，较为简便，酌情而用
    {
        scanf("%s",ss);
        ans=0;
        for(int i=0;i<strlen(ss);i++)
        {
            if(ss[i]=='C') ans+=pro(i,strlen(ss))*12.01;   //这里可以用映射map做，用if有点复杂
            if(ss[i]=='H') ans+=pro(i,strlen(ss))*1.008;
            if(ss[i]=='O') ans+=pro(i,strlen(ss))*16.00;
            if(ss[i]=='N') ans+=pro(i,strlen(ss))*14.01;
        }
        printf("%.3f\n",ans);  //保留三位小数输出
    }
}
