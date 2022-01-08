#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>

using namespace std;


const int MAXN=30;
int a[MAXN];
int cnt[4];
vector<char> ans;

bool get(){
    scanf("%d",&a[1]);
    if(a[1]==0)return false;
    for(int i=2;i<=24;i++){
        scanf("%d",&a[i]);
    }
    return true;
}
int find_num(){
    memset(cnt,0,sizeof(cnt));
    cnt[a[7]]++;
    cnt[a[8]]++;
    cnt[a[9]]++;
    cnt[a[12]]++;
    cnt[a[13]]++;
    cnt[a[16]]++;
    cnt[a[17]]++;
    cnt[a[18]]++;
    int t=max(cnt[1],cnt[2]);
    return max(t,cnt[3]);

}
void change(char x){
    if(x=='A'){
        int dis=a[1];a[1]=a[3];
        a[3]=a[7];a[7]=a[12];
        a[12]=a[16];a[16]=a[21];
        a[21]=a[23];a[23]=dis;
    }
    if(x=='B'){
        int dis=a[2];a[2]=a[4];
        a[4]=a[9];a[9]=a[13];
        a[13]=a[18];a[18]=a[22];
        a[22]=a[24];a[24]=dis;
    }
    if(x=='C'){
        int dis=a[11];a[11]=a[10];
        a[10]=a[9];a[9]=a[8];
        a[8]=a[7];a[7]=a[6];
        a[6]=a[5];a[5]=dis;
    }
    if(x=='D'){
        int dis=a[20];a[20]=a[19];
        a[19]=a[18];a[18]=a[17];
        a[17]=a[16];a[16]=a[15];
        a[15]=a[14];a[14]=dis;
    }
    if(x=='E'){
        int dis=a[24];a[24]=a[22];
        a[22]=a[18];a[18]=a[13];
        a[13]=a[9];a[9]=a[4];
        a[4]=a[2];a[2]=dis;
    }
    if(x=='F'){
        int dis=a[23];a[23]=a[21];
        a[21]=a[16];a[16]=a[12];
        a[12]=a[7];a[7]=a[3];
        a[3]=a[1];a[1]=dis;
    }
    if(x=='G'){
        int dis=a[14];a[14]=a[15];
        a[15]=a[16];a[16]=a[17];
        a[17]=a[18];a[18]=a[19];
        a[19]=a[20];a[20]=dis;
    }
    if(x=='H'){
        int dis=a[5];a[5]=a[6];
        a[6]=a[7];a[7]=a[8];
        a[8]=a[9];a[9]=a[10];
        a[10]=a[11];a[11]=dis;
    }
}

bool dfs(int d,int md){
    int k=8-find_num();
    if(k==0)return true;
    if(d+k>md)return false;

    change('A');
    ans.push_back('A');
    if(dfs(d+1,md))return true;
    change('F');
    ans.pop_back();

    change('B');
    ans.push_back('B');
    if(dfs(d+1,md))return true;
    change('E');
    ans.pop_back();

    change('C');
    ans.push_back('C');
    if(dfs(d+1,md))return true;
    change('H');
    ans.pop_back();

    change('D');
    ans.push_back('D');
    if(dfs(d+1,md))return true;
    change('G');
    ans.pop_back();

    change('E');
    ans.push_back('E');
    if(dfs(d+1,md))return true;
    change('B');
    ans.pop_back();


    change('F');
    ans.push_back('F');
    if(dfs(d+1,md))return true;
    change('A');
    ans.pop_back();


    change('G');
    ans.push_back('G');
    if(dfs(d+1,md))return true;
    change('D');
    ans.pop_back();

    change('H');
    ans.push_back('H');
    if(dfs(d+1,md))return true;
    change('C');
    ans.pop_back();

    return false;
}
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int max_deep=1;

    while(get()){
        int k=find_num();
        if(k==8){
            printf("No moves needed");
            printf("\n%d\n",a[7]);
            continue;
        }
        max_deep=1;
        while(1){
            if(dfs(0,max_deep)){
                for(int i=0;i<ans.size();i++)printf("%c",ans[i]);
                ans.clear();
                printf("\n%d\n",a[7]);
                break;
            }
            max_deep++;
        }
    }
}
