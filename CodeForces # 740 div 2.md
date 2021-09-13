[CodeForces]: https://codeforces.com/contest/1561



## A. Simply Strange Sort

### 题目思路：

给一个数组$a$，下标为奇数时，满足$a_i>a_{i+1}$时，更改$a_i和a_{i+1}$的位置，$ans++$,并对所有下标为奇数的序列重复这种操作。下标为偶数时也是同样操作。操作顺序起点从$1$到$n$，直到整个序列是一个有序序列就停止，输出$ans$的值（如果序列已经有序则为$0$）。这道题第一次做有好多地方没有理解清楚，开始打了个冒泡~~（第一印象确实很像）~~，莽错了好几发。

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int a[N];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long ans=0;
        bool ok=0;
        for(int i=1;i<n;i++){
            if(a[i]>a[i+1]){
                ok=1;
                break;
            }
        }
        while(ok){
            ans++;
            int p;
            if(ans%2==1)p=1; //确定初始起点
            else p=2;
            for(int i=p;i<n;i+=2){  //进行替换
                if(a[i]>a[i+1]){
                    swap(a[i],a[i+1]);
                }
            }
            ok=0;
            for(int i=1;i<n;i++){ //判断
                if(a[i]>a[i+1]){
                    ok=1;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}
```

## B. Charmed by the Game

### 题目思路：

首先本题有个概念需要理解——破发，对于一个球类游戏，A是发球局，但是B赢了本场比赛，那么称

B完成了破发。

然后给定$a$,$b$,分别为A赢的局数和B赢的局数，开始谁发球都可以，但每局结束必须换发，问最后有多少个可能的破发局，并输出所有情况。

此题需要设一个方程，总局数$sum=a+b$,对于A来说，$a=x+p_a-p_b,b=y+p_b-p_a$,其中$x$为$a$的发球局数$=\frac{a+b}{2}或者\frac{a+b+1}{2}[取决于谁先发球]$，$p_a$为$a$赢的破发局数。$y$为$b$的发球局数$=sum-x$，$p_b$为$b$赢的破发局数。两式相加可得到$a+b=x+y$，这样，就可以枚举每一个$p_a$，就可以得到$p_b=b-y+p_a$。同时注意谁先发球都可以，如果$a$先发球，那么$p_a∈[0,\frac{sum+1}{2}]$,否则$p_a∈[0,\frac{sum}{2}]$，最后输出答案就可以了。

###### 这题不确定量的关系比较复杂，有时设方程的思想能够理清思路

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
set<int> s;
 //这里用集合的操作，既可以满足顺序，也可以去重。
int main()
{
	int _;
	scanf("%d",&_);
	while(_--){
		int a,b,p,q;
		cin>>a>>b;
		p=(a+b+1)/2;q=(a+b)/2;//a先手比b的发球局多以局
		for(int i=0;i<=p;i++){
			int y=(a+i-p);
			if(y<=q&&y>=0){  //y的局数有限制
				s.insert(i+y);
			}
		}
		p=(a+b)/2;q=(a+b+1)/2;  //a后手
		for(int i=0;i<=p;i++){
			int y=(a+i-p);
			if(0<=y&&y<=q)s.insert(i+y);
		}
		cout<<s.size()<<endl;
		for(auto i:s){
			cout<<i<<" ";
		}
		cout<<endl;
		s.clear();
	}
}
```

## C. Deep Down Below

### 题目思路:

有$n$个洞口，每个洞口里有$k$个怪物，排成一行，一个战士拥有一个初始值战斗力$p$,当战斗力大于怪兽生命值时才能打过，每打过一个怪兽就加$1$点战斗力，每个洞必须把所有怪物都打过才能进入下一个洞。问战士初始战斗力的最小值是多少？

其实这道题我第一次做的时候很清楚是二分，但是二分的值出了问题。对于每个洞$i$可以简化成一个值$a_i$,代表通过这个洞的最小战斗力，也就等于洞中的最大生命-位置+2，然后直接对最小战斗力的值进行二分，$judge$函数是从所有洞最小战斗力从小到大进行判断，能通过就小一点，不能通过就大一点。相当于最大值最小的二分、

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ull;
 
const int N=1e5+10;
struct node{
    ull st,ed;
    bool operator < (const node& k){
        if(st==k.st){
            return ed>k.ed;
        }
        return st<k.st;
    }
}s[N];
int n;
bool judge(ull k){
    ull all=k;
    for(int i=1;i<=n;i++){
        if(all>=s[i].st){
            all+=s[i].ed;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int p;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p;
            s[i].ed=p;
            int x,mx=0;
            for(int j=1;j<=p;j++){
                cin>>x;
                if(mx<x-j+2)mx=x-j+2;
            }
            s[i].st=mx;
        }
        sort(s+1,s+1+n);;
        int l=1,r=1e9+10,mid;
        while(l<=r){
            mid=l+r>>1;
            if(judge(mid)){
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<l<<endl;
    }
}
```

## D. Up the Strip

### 题目思路：

给定$n$,$m$。从$1$到$n$，每个数可以减去一个数，但减完必须大于等于1。也可以除以一个数。步骤的执行顺序不同那么两方案也不同，问一共有多少种方法使得$n$经过变换后成为1。考虑方案数很多，要求答案模$m$。

对于这个题，可以很直接的写出暴力搜索算法,$dp[i]=\sum_{j=1}^{i-1}dp[i-j]+\sum_{j=2}^{i}dp[i/j]$ ,时间复杂度$O(n^2)$考虑到$2\le n\le2·10^5$，需要优化。第一个部分比较容易优化，$dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+...dp[1]$,可以提前维护前缀和$tot+=dp[i]$,那么$dp[i+1]+=tot$,这样第一部分就优化成了$O(n)$。

第二部分的优化有两种方式：

#### 1.整除分块优化

由于整除时向下取整的特性，就可以分块来优化。可以优化成$O(\sqrt{n})$,这样总的复杂度就$O(n\sqrt{n})$,对于$2·10^5$的时间复杂度是可以通过的。

#### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll dp[N];
ll n,m,sum,tot=1; 
int main()
{
	int id=1;
	cin>>n>>m;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=(dp[i]+tot)%m;
		id=2;
		while(i/id>=1){
			int q=i/id;
			int r=i/q;
			dp[i]=((dp[i]+(dp[q]*(r-id+1))%m))%m;
			//dp[i]=(dp[i]+dp[i/id])%m;
			id+=(r-id+1);
		}
		tot=(tot+dp[i])%m;
	}
	cout<<dp[n]<<endl;
}
```



#### 2.调整递推的更新顺序

由于$i/j$会向下取整，分析到这个范围是$[i*j,i*j+j-1]$，令$k∈[i*j,i*j+j-1]$，则每一个$dp[k]$

都要加上$dp[i]$。这样的区间操作可以在$O(logn)$的时间内完成，那么从时间复杂度就是$O(nlogn)$，可以通过$n\le4*10^6$的数据范围。不过实现细节上有很多种方法，第一种是复杂一点的线段树，第二种是简单的维护前缀和。维护前缀和就是设置前缀和数组$a[i]$,令$a[i*j]+=dp[i]$,$a[i*j+j]-=dp[i]$，同时答案更新为$dp[i]+=a[i]$,再加上第一部分维护的前缀和$tot$就好了。那么维护前缀和时为什么是$O(nlog n)$的时间复杂度呢。对于每一个$i$,更新时需要满足$i*j\le n$,那么当$i=1$时，枚举次数为$n$,当$i=2$,为$n/2$,当$i=3$,为$n/3$,当$i=n$时，为$1$,那么总和为:

$(n+n/2+n/3+n/4+···1)\Leftrightarrow n*(1+1/2+1/3+···1/n) \Leftrightarrow n* \int \frac{1}{x} *dx = n*logn $,

#### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=4e6+10;
typedef long long ll;
ll dp[N],a[N],n,m,tot;
int main()
{
	cin>>n>>m;
	dp[1]=1;
	for(ll i=1;i<=n;i++){
		a[i]=(a[i]+a[i-1])%m;
		dp[i]=((dp[i]+tot)%m+a[i])%m;
		for(ll j=2;j*i<=n;j++){
			ll l=j*i,r=j*i+j-1;
			if(r>n+1)r=n+1;
			//r=min(r,n+1);
			a[l]=(a[l]+dp[i])%m;
			a[r+1]=(a[r+1]-dp[i]+m)%m;
		}
		tot=(tot+dp[i])%m;
	}
	cout<<dp[n]<<endl;
}
```

## E. Bottom-Tier Reversals

### 题目思路：

给一个序列$a=[a_1,a_2,···,a_n]$,保证$n$为奇数,$n\le2021$规定每次只能对奇数做一个反转操作，即设奇数为$i$，那么$[1,i]$要进行反转，并且反转次数不能超过$\frac{5n}{2}$。输出每个序列要进行怎么样的反转才能使得整个序列从小到大有序，不能的输出-1。

其实很像紫书上的一道构造题，介绍构造入门的时候用的例题。不过区别在与此题之只能反转奇数并且还有反转次数限制。首先判断是否可以完成反转，可以观察到再反转的时候，奇数还是跑到奇数的位置上，偶数还是在偶数的位置上，那么就可以断定，如果就必须满足对于每一个$i$,都有$i\%2=a[i]\%2$，否则就没有答案。那么剩下都是有答案的，且要在反转到奇数的同时把相邻的偶数也反转到。首先要倒着来，找到等于$i$的$a[j]$，将$[1,j]$进行一次反转，第二步，找到等于$i-1$的$a[p]$,反转$p-1$,此时$a[j],a[p]$相邻，此时再把$[1,i]$反转，有$a[p],a[j]$相邻，再将$[1,j]$反转，有$a[j],a[p]$开头的序列，此时再反转$[1,i]$，就把$i$和$i-1$都排好了。如果对每一个奇数从大到小都来一遍是可行的，但是答案还有一个要求，就是不能超过$\frac{5n}{2}$ ,此时的次数为$\frac{5(n+1)}{2}$,那就不能对奇数做这样的操作，而是对偶数，操作是一致的，不过次数操作数变成了$\frac{5(n-1)}{2}$，就满足了。

### 代码

```c++



#include<bits/stdc++.h>
using namespace std;
const int N=2023;
int a[N];
vector<int> ans;
int n;
int findx(int x){
	for(int i=1;i<=n;i++){
		if(a[i]==x)return i;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		bool ok=1;
		for(int i=1;i<=n;i++){
			if(a[i]%2!=i%2){
				//cout<<a[i]<<" "<<i<<endl; 
				ok=0;
				break;
			}
		}
		if(!ok){
			cout<<-1<<endl;
			continue;
		}
		for(int i=n-1;i>=1;i-=2){
			int j=findx(i+1);
			ans.push_back(j);
			reverse(a+1,a+1+j);
			
			int p=findx(i);
			ans.push_back(p-1);
			reverse(a+1,a+p);
			ans.push_back(i+1);
			reverse(a+1,a+2+i);
			
			j=findx(i+1);
			ans.push_back(j);
			reverse(a+1,a+1+j);
			
			ans.push_back(i+1);
			reverse(a+1,a+2+i);
		}
		int len=ans.size();
		cout<<len<<endl;
		for(int i=0;i<len;i++){
			cout<<ans[i]<<" ";
		}
		if(len!=0)cout<<endl;
		ans.clear();
	}	
}
```

