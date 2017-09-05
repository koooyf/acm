#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,a[200];
	while(scanf("%d",&n)!=EOF)
	{
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>1) tot++;
		}
		int sum=a[1];
		for(int i=2;i<=n;i++)
			sum=sum^a[i];
		if(sum==0)
		{
			if(tot>=2)
				printf("No\n");
			else if(tot==0)
				printf("Yes\n");	
		}
		else
		{
			if(tot>=1)
				printf("Yes\n");
			else if(tot==0)
				printf("No\n");
		}

	}
	return 0;
}
