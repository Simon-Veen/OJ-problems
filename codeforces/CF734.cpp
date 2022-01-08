#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int a[N],ans[N][N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int minn=N;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i;j++){
                int d=(a[i]==i-j);
                ans[i][j]=ans[i-1][j]+d;
                if(j)ans[i][j]=max(ans[i][j],ans[i-1][j-1]);
                if(ans[i][j]>=k)minn=min(minn,j);
            }
        }
        if(minn==N)minn=-1;
        printf("%d\n",minn);
        memset(ans,0,sizeof(ans));
    }
}
/*

#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
char g[N][N];

int find_color(int i,int j){
    int k;
    for(k=0;k<26;k++){
        if(k+'a'!=g[i-1][j]&&k+'a'!=g[i][j-1]&&k+'a'!=g[i+1][j-1])return k;
    }
}
int main(){
    int _;
    scanf("%d",&_);
    while(_--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        if(n%2==1){
            if(k>=m/2&&(n-1)*m/2>=k-m/2&&(k-m/2)%2==0){
                printf("YES\n");
                int ptr=0,cnt=k;
                for(int i=1;i<=m;i+=2){
                    int p=find_color(1,i);
                    g[1][i]=g[1][i+1]=p+'a';
                    cnt--;
                }
                for(int i=2;i<=n&&cnt;i+=2){
                    for(int j=1;j<=m&&cnt;j+=2){
                        int p=find_color(i,j);
                        g[i][j]=g[i][j+1]=p+'a';
                        p=find_color(i+1,j);
                        g[i+1][j]=g[i+1][j+1]=p+'a';
                        cnt-=2;
                    }
                }
                 for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(g[i][j])continue;
                        int p=find_color(i,j);
                        g[i][j]=g[i+1][j]=p+'a';
                    }
                }
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        printf("%c",g[i][j]);
                    }
                    printf("\n");
                }
            }
            else printf("NO\n");
        }
        else if(m%2==1){
            if(2*k<=n*(m-1)&&k%2==0){
                printf("YES\n");
                int cnt=k;
                for(int i=1;i<=n&&cnt;i+=2){
                    for(int j=1;j<m-1&&cnt;j+=2){
                        int p=find_color(i,j);
                        g[i][j]=g[i][j+1]=p+'a';
                        p=find_color(i+1,j);
                        g[i+1][j]=g[i+1][j+1]=p+'a';
                        cnt-=2;
                    }
                }
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(g[i][j])continue;
                        int p=find_color(i,j);
                        g[i][j]=g[i+1][j]=p+'a';
                    }
                }
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        printf("%c",g[i][j]);
                    }
                    printf("\n");
                }
            }
            else printf("NO\n");
        }
        else {
            if(k*2<=n*m&&k%2==0){
                printf("YES\n");
                int cnt=k;
                for(int i=1;i<=n&&cnt;i+=2){
                    for(int j=1;j<=m&&cnt;j+=2){
                        int p=find_color(i,j);
                        g[i][j]=g[i][j+1]=p+'a';
                        p=find_color(i+1,j);
                        g[i+1][j]=g[i+1][j+1]=p+'a';
                        cnt-=2;
                    }
                }
                //printf("%d %d\n",i,j);
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        if(g[i][j])continue;
                        int p=find_color(i,j);
                        g[i][j]=g[i+1][j]=p+'a';
                    }
                }
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=m;j++){
                        printf("%c",g[i][j]);
                    }
                    printf("\n");
                }
            }
            else printf("NO\n");
        }
        memset(g,0,sizeof(g));
    }
}


/*


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--){
       int n,m,k;
       scanf("%d%d%d",&n,&m,&k);
       if(m%2==1){
           if(k%2==0&&k<=n*(m-1)/2){
            printf("YES\n");
           }
           else printf("NO\n");
       }
       else if(n%2==1){
            if(m/2<=k&&(k-m/2)%2==0&&(k-m/2)<=(n-1)*m/2){
                printf("YES\n");
            }
            else printf("NO\n");
       }
       else{
            if(k%2==0&&k*2<=n*m){
                printf("YES\n");
            }
            else printf("NO\n");
       }
    }
}

/*

#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
struct node{
    int numa,numb,numc,numd,nume;
}num[MAXN];
int t,n;
bool cmpa(node x,node y){
    return x.numa>y.numa;
}
bool cmpb(node x,node y){
    return x.numb>y.numb;
}
bool cmpc(node x,node y){
    return x.numc>y.numc;
}
bool cmpd(node x,node y){
    return x.numd>y.numd;
}
bool cmpe(node x,node y){
    return x.nume>y.nume;
}
int chose_a(){
    sort(num+1,num+1+n,cmpa);
    int ans=0,tot=0;
    for(int i=1;i<=n;i++){
        if(tot+num[i].numa>0){
            tot+=num[i].numa;
            ans++;
        }
        else break;
    }
    return ans;
}
int chose_b(){
    sort(num+1,num+1+n,cmpb);
    int ans=0,tot=0;
    for(int i=1;i<=n;i++){
        if(tot+num[i].numb>0){
            tot+=num[i].numb;
            ans++;
        }
        else break;
    }
    return ans;
}
int chose_c(){
    sort(num+1,num+1+n,cmpc);
    int ans=0,tot=0;
    for(int i=1;i<=n;i++){
        if(tot+num[i].numc>0){
            tot+=num[i].numc;
            ans++;
        }
        else break;
    }
    return ans;
}
int chose_d(){
    sort(num+1,num+1+n,cmpd);
    int ans=0,tot=0;
    for(int i=1;i<=n;i++){
        if(tot+num[i].numd>0){
            tot+=num[i].numd;
            ans++;
        }
        else break;
    }
    return ans;
}
int chose_e(){
    sort(num+1,num+1+n,cmpe);
    int ans=0,tot=0;
    for(int i=1;i<=n;i++){
        if(tot+num[i].nume>0){
            tot+=num[i].nume;
            ans++;
        }
        else break;
    }
    return ans;
}



int main(){
    //freopen("1.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        string p;
        for(int i=1;i<=n;i++){
            cin>>p;
            int len=p.size();
            int la=0,lb=0,lc=0,ld=0,le=0;
            for(int i=0;i<len;i++){
                if(p[i]=='a')la++;
                if(p[i]=='b')lb++;
                if(p[i]=='c')lc++;
                if(p[i]=='d')ld++;
                if(p[i]=='e')le++;
            }
            num[i].numa=la-lb-lc-ld-le;
            num[i].numb=lb-la-lc-ld-le;
            num[i].numc=lc-la-lb-ld-le;
            num[i].numd=ld-la-lb-lc-le;
            num[i].nume=le-la-lb-lc-ld;
           // printf("%d %d %d %d %d\n",num[i].numa,num[i].numb,num[i].numc,num[i].numd,num[i].nume);
        }
        int ans=chose_a();
        ans=max(ans,chose_b());
        ans=max(ans,chose_c());
        ans=max(ans,chose_c());
        ans=max(ans,chose_d());
        ans=max(ans,chose_e());
        printf("%d\n",ans);
        memset(num,0,sizeof(num));
    }
}


/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int MAXN=2e5+10;
int a[MAXN],ac[MAXN],ans[MAXN],cnt[MAXN];
struct node{
    int id,val;
};
vector<node> v;
bool cmp(node a,node b){
    return a.val<b.val;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ac[a[i]]++;
        }
        int tot=0;
        for(int i=1;i<=n;i++){
            if(ac[a[i]]>=k&&cnt[a[i]]+1<=k){
                ans[i]=++cnt[a[i]];
            }
            else if(ac[a[i]]<k){
                node jj;
                jj.id=i;jj.val=a[i];
                v.push_back(jj);
                tot++;

            }
        }
        if(tot>=k){
            sort(v.begin(),v.end(),cmp);
            int w=tot/k,c=0,time=0;
            int len=v.size();
            for(int i=0;i<len;i++){
                ans[v[i].id]=++c;
                if(c==k){
                    c=0;
                    time++;
                    if(time==w)break;
                }
            }
        }
        /* Íü¼ÇÅÅÐòÁË
        if(tot>=k){
            int c=0,time=0;
            for(int i=1;i<=n;i++){
                if(ac[a[i]]<k&&cnt[a[i]]+1<=k){
                    ans[i]=++cnt[a[i]];
                }
            }
        }
        */
        /*
        for(int i=1;i<=n;i++){
            printf("%d ",ans[i]);
            ac[a[i]]=ans[i]=cnt[a[i]]=0;
            a[i]=0;
        }
        printf("\n");
        v.clear();
    }
}


/*
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",a);
        int len=strlen(a);
        int two=0,one=0;
        for(int i=0;i<len;i++){
            ac[a[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(ac[i]>0&&ac[i]>=2){
                two+=2;
            }
            else if(ac[i]>0&&ac[i]<2){
                one++;
            }
        }
        printf("%d\n",two/2+one/2);
        memset(ac,0,sizeof(ac));
    }

}

/*
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n%3==0){
            printf("%d %d\n",n/3,n/3);
        }
        else if(n%3==1){
            printf("%d %d\n",1+n/3,n/3);
        }
        else if(n%3==2){
            printf("%d %d\n",n/3,1+n/3);
        }
    }
}

*/
