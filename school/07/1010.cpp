#include<cstdio>
using namespace std;
int main()
{
	int t,n,m,a[300000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int k=0;(1<<k)<=m;k++)
		{
			for(int i=1<<k;i<n;i++)
			{
				if((m>>k)&1)
					a[i]^=a[i-(1<<k)];
			}
		}
			printf("%d",a[0]);
		for(int i=1;i<n;i++)
			printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}
