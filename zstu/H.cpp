#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long f[1000];
void fff()
{
	f[0]=1,f[1]=1;
	for(int i=2;i<=90;i++)
		f[i]=f[i-1]+f[i-2];
}
int main()
{
	int t,n;
	long long m;
	scanf("%d",&t);
	fff();
	while(t--)
	{
		scanf("%d%lld",&n,&m);
		if(n>=3)
		{
		while(true)
		{
			if(m>f[n-1])
			{
				n--;
				m=m-f[n];
			}
			else
			{
				n--;
			}
			if(n==2)break;
		}
		}
		if(m==2)
			printf("b\n");
		else if(m==1||m==3)
			printf("a\n");
	}
	return 0;
}
