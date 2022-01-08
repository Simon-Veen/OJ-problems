
#include<cstdio>
#include<cstring>
const int maxn=128+2;
bool flag1=true;
char s[maxn];
int len1;
void dfs(int &i){
if(s[i]==')' || s[i]==']'){
	flag1=false;
	return ;
}
else if(s[i]=='('){
	while(true){
	i++;
	if(i>=len1){
		flag1=false;return ;
	}
	if(s[i]==')')return;
	else dfs(i);
		}
}
else if(s[i]=='['){
	while(true){
	i++;
	if(i>=len1){
	flag1=false;return ;
	}
	if(s[i]==']')return ;
	else dfs(i);
		}
}
}
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
		flag1=true;
		gets(s);
		len1=strlen(s);
		if(len1)         //空串输出Yes
		{
		for(int i=0;i<len1;i++){
			if(flag1)dfs(i);
		}
		if(flag1)printf("Yes\n");
		else printf("No\n");
		}
		else printf("Yes\n");
	}
	return 0;
}