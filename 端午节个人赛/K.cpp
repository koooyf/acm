#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,t,a[3000],b[3000],c[3000],dp[5005];
	double e[3000],w[3000];
	while(scanf("%d%d",&n,&t)!=EOF)
	{
		int sum=0,ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		for(int i=1;i<=n;i++)
		{
			e[i]=double(b[i])/double(c[i]);
		//	w[i]=double(a[i])/double(c[i]);
		}
		/*for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(w[i]<w[j])
				{
					double p=w[i];
					w[i]=w[j];
					w[j]=p;
					int x=a[i];
					a[i]=a[j];
					a[j]=x;
					x=b[i];
					b[i]=b[j];
					b[j]=x;
					x=c[i];
					c[i]=c[j];
					c[j]=x;
				}
			}
		}*/
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(e[i]<e[j])
				{
					double p=e[i];
					e[i]=e[j];
					e[j]=p;
					int x=a[i];
					a[i]=a[j];
					a[j]=x;
					x=b[i];
					b[i]=b[j];
					b[j]=x;	
					x=c[i];
					c[i]=c[j];
					c[j]=x;
				}		
			}	
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=t;j>=c[i];j--)
			{
				dp[j]=max(dp[j-c[i]]+a[i]-b[i]*j,dp[j]);
			}
		}
		int maxn=0;
		for(int i=1;i<=t;i++)
			maxn=max(maxn,dp[i]);
		printf("%d\n",maxn);
	}
	return 0;
}
