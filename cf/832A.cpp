#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	long long n,k;
	scanf("%lld%lld",&n,&k);
	if((n/k)%2==1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
