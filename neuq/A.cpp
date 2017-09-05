#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
double dp[3][45][45][45];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		dp[0][n][n+1][n]=1;
		for(int i=n;i>=0;i--)
		{
			for(int j=n+1;j>=0;j--)
			{
				for(int k=n;k>=0;k--)
				{
					double ii=i,jj=j,kk=k;
					dp[1][i][j][k]=dp[0][i][j+1][k]*(jj+1)/(ii+jj+1+kk)+dp[1][i+1][j][k]*(ii+1)/(jj+ii+1+kk)+dp[2][i][j][k+1]*(kk+1)/(ii+jj+kk+1);
					dp[2][i][j][k]=dp[0][i][j][k]*(j+1)/(ii+jj+1+kk)+dp[1][i][j+1][k]*(jj+1)/(ii+jj+1+kk)+dp[2][i+1][j][k]*(ii+1)/(ii+1+jj+kk);
				}
			}
		}
		printf("%.9lf\n",dp[1][0][0][0]);
	}
	return 0;
}
