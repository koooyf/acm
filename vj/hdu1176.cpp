#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,mp[100005][15],dp[100005][15],maxx=0;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int x,t;
		memset(dp,0,sizeof(dp));
		int maxxx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&t);
			dp[t][x]++;
			maxx=max(maxx,t);
		}
		for(int i=maxx;i>=0;i--)
		{
			dp[i][0]+=max(dp[i+1][0],dp[i+1][1]);
			for(int j=1;j<10;j++)
				dp[i][j]+=max(max(dp[i+1][j],dp[i+1][j+1]),dp[i+1][j-1]);
			dp[i][10]+=max(dp[i+1][9],dp[i+1][10]);
		}
		printf("%d\n",dp[0][5]);
	}
	return 0;
}
