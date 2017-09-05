#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
ll prime[20];
ll quick_mul(ll a,ll b,ll mod)
{
	ll ans=0;
	a=a%mod;
	while(b)
	{
		if(b&1) ans=(ans+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return ans;
}
ll mod_pow(ll a, ll b,ll mod)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
ll gcdEx(ll a, ll b, ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	else
	{
		ll r=gcdEx(b,a%b,x,y);
		ll t=x;
		x=y;
		y=t-a/b*y;
		return r;
	}
}

ll getC(ll n,ll m,int cur)
{
	ll p=prime[cur];
	if(m>n)
	return 0;
	if(m>n-m)
		m=n-m;
	ll ans=1;
	for(ll i=1;i<=m;i++)
	{
		ll a=(n+i-m)%p;
		ll b=i%p;
		ans=quick_mul(ans,quick_mul(a,mod_pow(b,p-2,p),p),p);
	}
	return ans%p;
}
ll Lucas(ll n,ll k, int cur)
{
	ll p=prime[cur];
	if(k==0)
		return 1%p;
	return quick_mul(getC(n%p,k%p,cur),Lucas(n/p,k/p,cur),p);
}

int main()
{
	int t;
	long long Mod,n,m,a[20],cnt=0;
	int k;
	scanf("%d",&t);
	while(t--)
	{
		Mod=1;
		cnt=0;
		scanf("%lld%lld%d",&n,&m,&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%lld",&prime[i]);
			Mod*=prime[i];
		}
		for(int i=1;i<=k;i++)
		{
			a[i]=Lucas(n,m,i)%prime[i];
		}
		for(int i=1;i<=k;i++)
		{
			ll x,y,tmp;
			ll tot=Mod/prime[i];
			ll ans=gcdEx(tot,prime[i],x,y);
			if(x<0)
			{
				x=-x;
				tmp=quick_mul(tot,x,Mod);
				tmp=quick_mul(tmp,a[i],Mod);
				tmp=-tmp;
			}
			else
			{
				tmp=quick_mul(tot,x,Mod);
				tmp=quick_mul(tmp,a[i],Mod);
			}
			cnt=(cnt+tmp)%Mod;
			if(cnt<0)
				cnt+=Mod;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
