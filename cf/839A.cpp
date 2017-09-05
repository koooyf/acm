#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,k,a[200],ans=0,tot=0,kk=-1;
	bool f=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans+=a[i];
		if(ans>8)
		{
			ans=ans-8;
			tot+=8;
		}
		else
		{
			tot+=ans;
			ans=0;
		}
		if(tot>=k&&f==0)
		{
			kk=i;
			f=1;
		}
	}
	printf("%d\n",kk);
	return 0;
}
