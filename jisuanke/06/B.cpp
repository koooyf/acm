#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
	int n,num[200],ans[200][200],dp[105][10005],sum=0,ddp[105][10005]={0};
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		memset(ans,0,sizeof(ans));
		memset(dp,0,sizeof(dp));
		memset(ddp,0,sizeof(ddp));
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
			for(int j=1;j<=num[i];j++)
			{
				scanf("%d",&ans[i][j]);
				ans[i][j]+=ans[i][j-1];
			}
		}
		int cnt=0;
		if(sum%2)
			cnt=sum/2+1;
		else
			cnt=sum/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=num[i]&&j<=cnt;j++)
			{
				for(int k=cnt;k>=j;k--)
				{
					dp[i][k]=max(dp[i][k],dp[i-1][k-j]+ans[i][j]);
					dp[i][k]=max(dp[i-1][k],dp[i][k]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=num[i]&&j<=sum-cnt;j++)
			{
				for(int k=sum-cnt;k>=j;k--)
				{
					ddp[i][k]=max(ddp[i][k],ddp[i-1][k-j]+ans[i][num[i]]-ans[i][num[i]-j]);
					ddp[i][k]=max(ddp[i][k],ddp[i-1][k]);
				}
			}
		//	for(int j=1;j<=sum-cnt;j++)
		//		printf("%d ",ddp[i][j]);
		//	printf("\n");
		}
		if(dp[n][cnt]>ddp[n][sum-cnt])
			printf("win\n");
		else if(dp[n][cnt]==ddp[n][sum-cnt])
			printf("tie\n");
		else
			printf("lose\n");
//		printf("%d %d %d\n",sum-cnt,ddp[n][sum-cnt],dp[n][cnt]);
	}
	return 0;
