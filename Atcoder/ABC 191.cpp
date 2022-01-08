/*
4 4
....
.##.
.#..
....
*/

#include<cstdio>
char box[14][14];

int dx[]={0,0,1,1};
int dy[]={0,1,0,1};

int main()
{
    int h,w;
    long long int ans = 0;
    scanf("%d%d",&h,&w);
    for(int i = 0;i < h;i++){
            scanf("%s",&box[i]);
    }
    int cnt=0;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
                cnt=0;
                for(int p = 0;p < 4;p++){
                    int cx=i+dx[p];
                    int cy=j+dy[p];
                    if(cx>=0 && cy>=0 && cx < h && cy < w && box[cx][cy]=='#')cnt++;
                }
                if(cnt==1 || cnt==3)ans++;
                }
    }
    printf("%lld",ans);
}

/*
ABC 191 B

#include<cstdio>

int main()
{
    int n;
    long long int x,a;
    scanf("%d%lld",&n,&a);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x);
        if(a!=x)printf("%lld ",x);
    }
}

ABC 191 A
#include<cstdio>

int main()
{
    int v,t,s,d;
    scanf("%d%d%d%d",&v,&t,&s,&d);
    if(v*t>d||v*s<d)printf("Yes");
    else printf("No");
}
*/
