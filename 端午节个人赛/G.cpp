#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			long long ans=1;
			for(int j=1;j<=m;j++)
				ans=(ans*i)%1000000007;
			sum=(sum+ans%1000000007)%1000000007;
		}
	printf("%lld\n",sum);
	}
	return 0;
}

