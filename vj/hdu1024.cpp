#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
long long n,m,a[1000005],dp[1000005],maxn[1000005];
int main()
{
	while(scanf("%lld%lld",&m,&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		memset(dp,0,sizeof(dp));
		memset(maxn,0,sizeof(maxn));
		long long maxx;
		for(int i=1;i<=m;i++)
		{
			 maxx=-1000000000;
			for(int j=i;j<=n;j++)
			{
				dp[j]=max(dp[j-1]+a[j],maxn[j-1]+a[j]);
				maxn[j-1]=maxx;
				maxx=max(maxx,dp[j]);			
			}
		}
		printf("%lld\n",maxx);
	}
	return 0;
}
