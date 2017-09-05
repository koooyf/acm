#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 100006
const int mod=1e9+7;
bool vis[N];
int  prime[N],mu[N],pre[N];
void Mobius()
{
	memset(vis,0,sizeof(vis));
	mu[1]=1;
	int cnt=0;
	for(int i=2;i<N;i++)
	{
		if(!vis[i])
		{
			prime[cnt++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<cnt&&prime[j]*i<N;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
			else
				mu[i*prime[j]]=-mu[i];
		}	
	}
}
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1) 
			ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	int ca,t;
	long long sum[N];
	scanf("%d",&t);
	Mobius();
	while(t--)
	{
		ca++;
		long long ans=0;
		int n,a[N];
		scanf("%d",&n);
		memset(pre,0,sizeof(pre));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			pre[a[i]]++;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<N;i++)
			pre[i]+=pre[i-1];
		for(int i=2;i<=a[1];i++)
		{
			sum[i]=1;
			for(int j=0;j<N;j=j+i)
			{
				long long cnt;
				if(j==0) cnt=pre[j+i-1];
				else if(j+i-1>100000) 
					cnt=pre[100000]-pre[j-1];
				else cnt=pre[j+i-1]-pre[j-1];
				if(j/i==0&&cnt)
				{
					sum[i]=0;
					break;
				}
				sum[i]=(sum[i]*qpow(j/i,cnt))%mod;
			}
		}
		for(int i=2;i<=a[1];i++)
		{
			for(int j=i;j<=a[1];j=i+j)
			{
				ans=(ans+mu[j/i]*sum[j])%mod;		
			}
		}
		printf("Case #%d: %lld\n",ca,ans);
	}
	return 0;
}
