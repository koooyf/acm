#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int t,n,a[2000],sum[2000],mx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mx=-1;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[a[i]]++;
			mx=max(mx,sum[a[i]]);
		}
		int where=0;
		for(int i=1;i<=1000;i++)
		{
			if(sum[i]==mx)
			{
				where=i;
				printf("%d",i);
				break;
			}
		}
		for(int i=1;i<=1000;i++)
		{
			if(sum[i]==mx&&i!=where)
			{
				printf(" %d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
