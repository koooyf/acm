#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod = 1000000007;
long long mod_pow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1) ans=((ans%mod)*(a%mod))%mod;
			a=((a%mod)*(a%mod))%mod;
			b>>=1;
	}
	return ans;
}
long long x[1000000],dp[1000000];
int main()
{
	long long n,ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&x[i]);
	sort(x+1,x+n+1);
	dp[n-1]=x[n];
	for(int i=n-2;i>=1;i--)
	{
		dp[i]=((2*(dp[i+1]%mod))%mod+x[i+1]%mod)%mod;
	}
	for(int i=1;i<n;i++)
	{
		long long t=n-i-1;
		long long tnt=((mod_pow(2,t+1)%mod-1+mod)%mod*(x[i]%mod))%mod;
		ans=(ans%mod+(dp[i]%mod-tnt%mod+mod)%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
