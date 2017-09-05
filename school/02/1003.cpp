#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int main()
{
	long long n,a[250005],b[250005];
	while(scanf("%lld",&n)!=EOF)
	{
		long long minxx=0,maxx=2500050;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			a[i]=a[i]-i;
		}
		for(int i=1;i<=n;i++)
			scanf("%lld",&b[i]);
		sort(b+1,b+n+1);
		maxx=-2500050;
		for(int i=b[1];i<=n;i++)
		{
			if(a[i]>maxx)
			{
				maxx=a[i];
			}			
		}
		a[n+1]=maxx-(n+1);
		for(int i=n;i>=1;i--)
		{
			a[i]=max(a[i],a[i+1]);
		}
		long long sum=maxx%mod;
		for(int i=2;i<=n;i++)
		{
				sum=(sum+a[b[i]])%mod;		
		}
		printf("%lld\n",sum);
	}
	return 0;
}
