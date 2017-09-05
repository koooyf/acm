#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int a[200],n,maxx=0,x;
	bool f=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxx)
		{
			maxx=a[i];
			x=i;
		}
	}
	for(int i=x-1;i>=1;i--)
	{
		if(a[i+1]<=a[i])
		{
			f=0;
			break;
		}
	}
	for(int i=x+1;i<=n;i++)
	{
		if(a[i]!=maxx)
		{
			break;	
		}
		else
			x=i;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(a[i]>=a[i-1])
		{
			f=0;
			break;
		}
	}
	if(f) printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
