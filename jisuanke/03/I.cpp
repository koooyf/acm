#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	long long L,n,l,x[2000];
	while(scanf("%lld%lld%lld",&L,&n,&l)!=EOF)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		sort(x+1,x+n+1);
		long long cnt=x[1]+l;
		ans++;
		for(int i=2;i<=n;i++)
		{
			if(x[i]>cnt)
			{
				cnt=x[i]+l;
				ans++;
			}
//			printf("%lld\n",x[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
