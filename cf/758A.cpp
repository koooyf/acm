#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,a[200],maxx;
	scanf("%d",&n);
	maxx=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(maxx-a[i]);
	}
	printf("%d\n",sum);
	return 0;
}
