#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define MAXN 1000005
const int mod = 1000000007;
bool vis[MAXN];
int mu[MAXN]={0},prime[MAXN],sum[MAXN]={0};
void Mobius()
{
	memset(vis,false,sizeof(vis));
	mu[1]=1;
	int cnt=0;
	for(int i=2;i<MAXN;i++)
	{
		if(!vis[i])
		{
			prime[cnt++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<cnt&&prime[j]*i<MAXN;j++)
		{
			vis[i*prime[j]]=true;
			if(i%prime[j]==0)
			{
				mu[i*prime[j]]=0;
				break;
			}
			else mu[i*prime[j]]=-mu[i];
		}
	}
}
int n;
typedef long long ll;
ll g[MAXN]={0};
void get()
{
	for(int i=1;i<MAXN;i++)
	{
		g[i]=(g[i]+1)%mod;
		for(int j=i+1;j<MAXN;j=j+i)
		{
			g[j]=(g[j]+1)%mod;
		}
	}
	for(int i=1;i<MAXN;i++)
		g[i]=(g[i]+g[i-1])%mod;
	for(int i=1;i<MAXN;i++)
		g[i]=(g[i]+g[i-1])%mod;
} 
int main()
{
	get();
	Mobius();
	for(int i=1;i<MAXN;i++)
	{
		mu[i]=(mu[i]+mu[i-1]);
	}
	while(scanf("%d",&n)!=EOF)
	{
		ll ans=0;
		int k;
		for(int i=1;i<=n;i=k+1)
		{
			k=n/(n/i);
			ans=(ans+(mu[k]-mu[i-1]+mod)%mod*g[n/i])%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
