#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1e6+10000;
int phi[maxn+10];
int primes[maxn+10],tot=0;
bool isPrime[maxn+10];
void getphi()
{
	memset(isPrime,true,sizeof(isPrime));
	phi[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(isPrime[i])
		{
			primes[++tot]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=tot;j++)
		{
			if(i*primes[j]>=maxn) break;
			isPrime[i*primes[j]]=false;
			if(i%primes[j]==0)
			{
				phi[i*primes[j]]=phi[i]*primes[j];
				break;
			}
			phi[i*primes[j]] = phi[i]*(primes[j]-1);
		}
	}
	phi[1]=0;
}
long long vis[maxn]={0};
int main()
{
	int t,n,ca=0;
	scanf("%d",&t);
	memset(vis,0,sizeof(vis));
	getphi();
	for(int i=1;i<maxn;i++)
	{
		if(!vis[phi[i]])
		vis[phi[i]]=i;
	}
	for(int i=1;i<=10;i++)
	{
		printf("%lld ",vis[i]);
	}
	printf("\n");
	while(t--)
	{
		ca++;
		int a;
		scanf("%d",&n);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
		/*	if(!vis[a])
			{
				int j=1;
				while(!vis[a+j])
				{
					j++;
				}
				ans+=vis[a+j];
			}
			else
				ans+=vis[a];*/
			int j=1;
			while(true)
			{
				if(isPrime[a+j])
				{
					ans+=(a+j);
					break;
				}
				j++;
			}
		}
		printf("Case %d: %lld Xukha\n",ca,ans);
	}
	return 0;
}
