#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	long long t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n%6==0)
			printf("%lld\n",n/6);
		else
			printf("%lld\n",n/6+1);
	}
	return 0;
}
