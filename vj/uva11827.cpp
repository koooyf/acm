#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	long long  n,a[1000];
		char c;
	scanf("%lld",&n);
	while(n--)
	{
		int i=0;
		long long maxx=0;
		while(true)
		{
			i++;
			scanf("%lld%c",&a[i],&c);
			if(c=='\n')
				break;
		}
		for(int j=1;j<i;j++)
		{
			for(int k=j+1;k<=i;k++)
			{

				maxx=max(maxx,gcd(a[j],a[k]));						
			}
		}
		printf("%lld\n",maxx);
	}
	return 0;
}
