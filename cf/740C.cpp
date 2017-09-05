#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,m,r,l;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int minx=10000000;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&l,&r);
			minx=min(minx,r-l+1);
		}
		printf("%d\n",minx);
		printf("0");
		for(int i=1;i<n;i++)
		{
			printf(" %d",i%minx);		
		}
		printf("\n");
	}
	return 0;
}
