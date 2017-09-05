#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long  n,a,b,c;
long long minxx(long long d,long long e)
{
	if(d<=e)
		return d;
	else return e;
}
int main()
{
	while(scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c)!=EOF)
	{
		int ans=4-n%4;
		long long minx=10000000000;
		if(ans==4)
		{
		   	printf("0\n");
			continue;
		}
		else if(ans==1)
		{
			minx=a;
			minx=minxx(minx,b+c);
			minx=minxx(minx,3*c);
		}
		else if(ans==2)
		{
			minx=minxx(b,2*a);
			minx=minxx(minx,2*c);
		}
		else if(ans==3)
		{
			minx=minxx(3*a,c);
			minx=minxx(minx,b+a);
		}
		printf("%I64d\n",minx);
	}	
	return 0;
}
