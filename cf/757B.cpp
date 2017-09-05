#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define N 100010
int prime[N],num[N],cnt=1,Hash[N];
void biao()
{
	for(int i=2;i<=100000;i++)
	{
		int tmp=sqrt(i);
		bool flag=0;
		for(int j=2;j<=tmp;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			prime[cnt]=i;
			cnt++;
		}
	}
}
int main()
{
	biao();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		Hash[num[i]]++;
		int tmp=sqrt(num[i]);
		for(int j=2;j<=tmp;j++)
		{
			if(num[i]%j==0)
			{
				Hash[j]++;
				if(j!=num[i]/j) Hash[num[i]/j]++;
			}
		}
	}
	int ans=1;
	for(int i=1;i<=cnt;i++)
	{
		if(ans<Hash[prime[i]])
		{
			ans=Hash[prime[i]];
		}
	}
	printf("%d\n",ans);
	return 0;
}
