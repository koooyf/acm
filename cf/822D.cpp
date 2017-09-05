#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define mod 1000000007
#define maxn 5000005
long long f[5000005];
int primes[maxn],tot=0;
bool isPrime[maxn];
void getPrime()
{
	memset(isPrime,true,sizeof(isPrime));
	for(int i=2;i<maxn;i++)
	{
		if(isPrime[i])
			primes[++tot]=i;
		for(int j=1;j<=tot;j++)
		{
			if(i*primes[j]>=maxn) break;
			isPrime[i*primes[j]]=false;
			if(i%primes[j]==0) break;
		}
	}
}
int main()
{
	int t,r,l;
	scanf("%d%d%d",&t,&l,&r);
	f[2]=1,f[3]=3,f[4]=3;
	getPrime();
	for(long long i=5;i<=r;i++)
	{
		int k=i;
		if(isPrime[k]==true)
			f[i]=(i*(i-1)/2)%mod;
		else
		{
		for(int j=1;;j++)
		{
			if(k==1) break;
			if(k%primes[j]==0)
			{
				f[i]=((f[primes[j]]*(i/primes[j])%mod)%mod+f[i/primes[j]])%mod;
				break;
			}	
		}
		}		
	}
	long long cnt=0;
	long long tt=1;
	for(int i=l;i<=r;i++)
	{
		cnt=((cnt+tt*f[i])%mod)%mod;	
		tt=(tt*t)%mod;
	}
	printf("%lld\n",cnt%mod);
	return 0;
}
