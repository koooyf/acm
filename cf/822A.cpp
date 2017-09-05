#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int t=min(a,b);
	long long sum=1;
	for(int i=1;i<=t;i++)
		sum*=i;
	printf("%lld\n",sum);
	return 0;
}
