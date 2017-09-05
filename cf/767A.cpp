#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,a[100005];
	bool f[100005];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int x=n;
	for(int i=1;i<=n;i++)
	{
		f[a[i]]=1;
		if(a[i]==x)
		{
			printf("%d",x);
			x--;
			while(f[x]==1)
			{
				printf(" %d",x);
				x--;
			}
			printf("\n");
		}
		else
		printf("\n");	
	}
	return 0;
}
