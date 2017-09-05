#include<cstdio>
#include<cstring>
using namespace std;
char s[10000];
int dp[6000][6000]={0},t,ans[6000];
int	dfs(int i,int j)
{
	int k;
	if(dp[i][j])
		return dp[i][j];
	if(dp[i+1][j-1]&&s[i]==s[j]&&j-i>1)
	{
		dp[i][j]=dfs(i,i+(j-i+1)/2-1)+1;
		dp[i][j]=dfs(j-(j-i+1)/2+1,j)+1;
	}
	else if(j-i==1&&s[i]==s[j])
	{	
		dp[i][j]=2;
	}
	return dp[i][j];	
}
int main()
{
	memset(dp,0,sizeof(dp));
	memset(ans,0,sizeof(dp));
	scanf("%s",s);
	t=strlen(s);
	for(int i=0;i<t;i++)
		dp[i][i]=1;
	for(int i=1;i<=t;i++)
	{
		for(int j=0;j+i-1<t;j++)
		{
			int k=dfs(j,j+i-1);
			ans[k]++;
		}
	}
	for(int i=t-1;i>=1;i--)
	{
		ans[i]+=ans[i+1];
	}
	printf("%d",ans[1]);
	for(int i=2;i<=t;i++)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}
