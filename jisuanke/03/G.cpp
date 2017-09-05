#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
# define N 3000
ll fac[N],p=10007;
void init()
{
	int i;
	fac[0]=1;
	for(i=1;i<3000;i++)
	{
		fac[i]=(fac[i-1]*i)%p;
//		if(i<=4)printf("%lld\n",fac[i]);
	}
}
ll mod_pow(ll x,ll n)
{
	ll res =1;
	while(n>0)
	{
		if(n&1) res=(res%p)*(x%p)%p;
		x=(x*x)%p;
		n>>=1;
	}
	return res;
}
ll C(ll n,ll m)
{
	if(m>n) return 0;
	return fac[n]*mod_pow(fac[m]*fac[n-m],p-2)%p;
}
ll Lucas(ll n,ll m)
{
	if(m==0) return 1;
	else return ((C(n%p,m%p)*Lucas(n/p,m/p))%(p*(n+1)))/(n+1);
}
int main()
{
	ll n;
//	init();
	while(scanf("%lld",&n)!=EOF)
	{
		p=10007;
		init();
		ll sum=Lucas(2*n,n);
		printf("%lld\n",sum);
	}
	return 0;
}
