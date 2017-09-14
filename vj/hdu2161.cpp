#include<cstdio>
#include<cstring>
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
int main()
{
 int n,ca=0;
 getphi();
 isPrime[1]=0;
 isPrime[2]=0;
	while(scanf("%d",&n)&&n>0)
	{
		ca++;
		if(isPrime[n])
			printf("%d: yes\n",ca);
		else
			printf("%d: no\n",ca);
	}
	return 0;
}
