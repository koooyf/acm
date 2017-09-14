#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int a[1000005],dp[1000005];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			dp[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(a[i]>a[j])
					dp[i]=max(dp[i],dp[j]+1);
			}
		}
		int maxx=0;
		for(int i=1;i<=n;i++)
			maxx=max(maxx,dp[i]);
		printf("%d\n",maxx);
	}
	return 0;
}
