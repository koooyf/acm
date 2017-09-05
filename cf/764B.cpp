#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n;
	int a[200005];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n/2;i++)
	{
		if(i<=n-i+1&&i%2)
		{
			int t=a[i];
			a[i]=a[n-i+1];
			a[n-i+1]=t;
		}
	}
	printf("%d",a[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",a[i]);
	printf("\n");
	return 0;
}
