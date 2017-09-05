#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int t,n,m,x,y;
	long long dp[50][50];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&x,&y);
		memset(dp,0,sizeof(dp));
		x++;y++;
		n++;m++;
		dp[1][1]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				  if(i==1&&j==1)
					dp[i][j]=1;
				  else
					  dp[i][j]+=dp[i-1][j]+dp[i][j-1];
					if((i==x&&j==y)||(i==x-2&&j==y-1)||(i==x-2&&j==y+1)||(i==x+2&&j==y-1)||(i==x+2&&j==y+1))
						dp[i][j]=0;
					if((i==x-1&&j==y-2)||(i==x-1&&j==y+2)||(i==x+1&&j==y-2)||(i==x+1&&j==y+2))
						dp[i][j]=0;
			}
		}
		printf("%lld\n",dp[n][m]);
	}
}
