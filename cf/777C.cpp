#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
int a[100005],c[100005],d[100005];
#define INF 1<<30
int main()
{
	int n,m,k,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
		c[i]=1;
	}

	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			if(a[j]<=x)
			{
				c[(i-1)*m+j]=c[(i-2)*m+j];
				a[j]=x;
			}
			else
			{
				c[(i-1)*m+j]=i;
				a[j]=x;
			}
		}
	}
	for(int i=1;i<=n;i++)
		d[i]=INF;	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			d[i]=min(d[i],c[(i-1)*m+j]);
		}
	}
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d%d",&n,&m);
		if(d[m]<=n)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
