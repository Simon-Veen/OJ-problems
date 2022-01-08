/*

哈希做法
速度：690ms

*/

#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN=4005;
int num[MAXN][4];
const int HashNum=2e7+3;//此题的数据量是1.6e7,所以2e7是够用的
int HashOrd[HashNum];
int HashTable[HashNum];

void insert_Hash(int k){

    int h=(k%HashNum+HashNum)%HashNum;
    while(HashOrd[h]&&HashTable[h]!=k){
        h++;
        if(h>HashNum)h-=HashNum;
    }
    if(!HashOrd[h]){
        HashOrd[h]=1;
        HashTable[h]=k;
    }
    else HashOrd[h]++;
}
int Look_Table(int k){
    int h=(k%HashNum+HashNum)%HashNum;

    while(HashOrd[h]&&HashTable[h]!=k){
        h++;
        if(h>HashNum)h-=HashNum;
    }
    return HashOrd[h];
}
int main()
{
    int n,T;
    int a,b,c,d;
    scanf("%d",&n);
    bool ok=0;
    while(n--){
        memset(HashOrd,0,sizeof(HashOrd));
        memset(HashTable,0,sizeof(HashTable));
        scanf("%d",&T);
        for(int i=1;i<=T;i++){
            scanf("%d%d%d%d",&num[i][0],&num[i][1],&num[i][2],&num[i][3]);
        }
        for(int i=1;i<=T;i++){
            for(int j=1;j<=T;j++){
                insert_Hash(num[i][0]+num[j][1]);
            }
        }
        long long int ans=0;
        for(int i=1;i<=T;i++){
            for(int j=1;j<=T;j++){
                ans+=Look_Table(-num[i][2]-num[j][3]);
            }
        }
        if(ok)printf("\n");
        if(!ok)ok=1;
        printf("%lld\n",ans);
    }
}
/*
unorder_map做法

速度：6120ms

#include<cstdio>
#include<unordered_map>
using namespace std;

const int MAXN=4005;
int box[MAXN][4];
unordered_map<int,int> Hash;
int main()
{
    int t,n;
    scanf("%d",&t);
    bool ok=0;
    while(t--){
        scanf("%d",&n);
        Hash.clear();
        for(int i=1;i<=n;i++){
           scanf("%d%d%d%d",&box[i][0],&box[i][1],&box[i][2],&box[i][3]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                Hash[box[i][0]+box[j][1]]++;
            }
        }
        long long int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans+=Hash[-box[i][2]-box[j][3]];
            }
        }
        if(ok)printf("\n");
        ok=1;
        printf("%lld\n",ans);

    }

}
*/
