#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int dp[200][200];
char s[2000],p[2000];
int main()
{
	while(scanf("%s%s",s+1,p+1)!=EOF)
	{
		int lens=strlen(s+1);
		int lenp=strlen(p+1);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=lens;i++)
		{
			for(int j=1;j<=lenp;j++)
			{
				if(s[i]==p[j])
					dp[i][j]=dp[i-1][j-1]+1;
				else
				{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		printf("%d\n",dp[lens][lenp]);
	}
	return 0;
}
