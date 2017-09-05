#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
const int N=1e5;
typedef long long ll;
ll mod_pow(ll a, ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=(ans%mod*a%mod)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
ll f[N],ni[N];
void init()
{
	f[0]=1;
	ni[0]=1;
	for(int i=1;i<=10005;i++)
	{
		f[i]=(f[i-1]*i)%mod;
		ni[i]=mod_pow(f[i],mod-2);
	}
}
int main()
{
	int t,n,k;
	long long d[10050];
	d[1]=0,d[2]=1;
	for(int i=3;i<=10000;i++)
		d[i]=(i-1)*(d[i-1]+d[i-2])%mod;
	scanf("%d",&t);
	init();
	while(t--)
	{
		scanf("%d%d",&n,&k);
		ll sum=0;
		for(int i=2;i<=n-k;i++)
		{
			sum=(sum+((f[n]*ni[n-i]%mod)*ni[i]%mod)%mod*d[i])%mod;
		}
		printf("%lld\n",(sum+1)%mod);
	}
	return 0;
}
