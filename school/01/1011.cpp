#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,ca=0;	
	long long k;
	while(scanf("%d%lld",&n,&k)!=EOF)
	{
		ca++;
		printf("Case #%d: ",ca);
			if(k>n-1)
			{
				k=k-n;
				long long t=k/(n-1);
				long long p=k%(n-1);
				t+=1;
				if(t%2==1)
				{
					if(p==0)
						printf("%d\n",n);
					else
						printf("%lld\n",p);
				}
				else
				{
					if(p==0)
						printf("%d\n",n-1);
					else
						printf("%lld\n",p);
				}
			}
			else
			{
				printf("%lld\n",k);
			}
	}
	return 0;
}
