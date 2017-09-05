#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,a[200],sum=0,rr,ll,l,r=1,tot=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		ll=-1;
		if(sum!=0)
		{
			printf("YES\n");
			printf("1\n");
			printf("1 %d\n",n);
			break;
		}
		else if(sum==0)
		{
			for(int i=n;i>=1;i--)
			{
				tot+=a[i];
				if(tot!=0)
				{
					ll=i;
					break;					
				}	
			}
		if(ll>=1)
		{
			printf("YES\n");
			printf("2\n");
			printf("1 %d\n",ll-1);
			printf("%d %d\n",ll,n);
			break;
		}
		}
		printf("NO\n");
		break;
	}
	return 0;
}
