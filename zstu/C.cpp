#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int t,n,a[2000];
	int mx,mn;
	scanf("%d",&t);
	while(t--)
	{
		mx=-1;mn=10000000;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
			mn=min(mn,a[i]);
		}
		printf("%d\n",mx-mn);
	}
	return 0;
}
