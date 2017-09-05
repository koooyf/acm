#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int t,n,a[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>1)
				tot++;
		}
		int sum=a[1];
		for(int i=2;i<=n;i++)
			sum=sum^a[i];
		if(sum==0)
		{
			if(tot>=2)
				printf("Brother\n");
			else if(tot==0)
				printf("John\n");
		}
		else
		{
			if(tot>=1)
				printf("John\n");
			else if(tot==0)
				printf("Brother\n");	
		}
	}
	return 0;
}
