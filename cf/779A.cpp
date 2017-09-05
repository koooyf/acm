#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,a[100],b[100],ans[10]={0},tot[10]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans[a[i]]++;		
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		tot[b[i]]++;
	}
	int sum=0,ff=0;
	bool f=0;
	for(int i=1;i<=5;i++)
	{
		if((ans[i]+tot[i])%2==1)
			f=1;
		else
		{
			if(ff==0)
			{
				ff+=(ans[i]-tot[i])/2;
			}
			else
			{
				if(ans[i]>tot[i])
				{
					if(ff<0)
					sum+=(ans[i]-tot[i])/2;
					else
						ff+=(ans[i]-tot[i])/2;
				}
				else
				{
					if(ff>0)
					sum+=(tot[i]-ans[i])/2;
					else
						ff+=(ans[i]-tot[i])/2;
				}
			}
		}
	}
	if(f==1)
		printf("-1\n");
	else
		printf("%d\n",sum);
	return 0;
}
