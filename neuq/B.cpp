#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,t,a[20];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=10;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+11);
		printf("%d %d\n",n,a[8]);
	}
	return 0;	
}
