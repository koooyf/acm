#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,a[200];
	bool dp[200]={0},ddp[200];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	memset(ddp,1,sizeof(ddp));
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	ddp[0]=0;
	if(a[1]%2)
	{
		dp[1]=1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j=j+2)
		{
			if(dp[i-j]&&a[i-j+1]%2&&a[i]%2)
				ddp[i]=0;
		}
		for(int j=1;j<=i;j=j+2)
		{
			if(!ddp[i-j]&&a[i-j+1]%2&&a[i]%2)
				dp[i]=1;
		}
//		printf("%d %d\n",dp[i],ddp[i]);
	}
	if(dp[n])
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
