#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n,k,a[200],w;
	scanf("%d",&n);
	while(n--)
	{
		bool f=0;
		scanf("%d%d",&k,&w);
		for(int i=1;i<=k;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+k+1);
		int ans=0;
		for(int i=1;i<=k;i++)
		{
			if(ans+a[i]>w)
			{
				f=1;
				printf("%d\n",i-1);
				break;
			}
			else if(ans+a[i]==w)
			{
				f=1;
				printf("%d\n",i);
				break;
			}
			ans+=a[i];
		}
		if(!f)
			printf("%d\n",k);
	}
	return 0;
}
