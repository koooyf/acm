#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int t,n,a[70000],sum[70000],w[70000];
	scanf("%d",&t);
	while(t--)
	{
		memset(sum,0,sizeof(sum));
		memset(w,0,sizeof(w));
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[a[i]]++;
			w[a[i]]=i;
		}
		sort(w,w+n+1);
		int j=0;
		while(w[j]==0)
			j++;
		double minxx=1000,x=0,y=0;
		while(w[j]<=n)
		{
			x++;
			y+=sum[a[w[j]]];
			if(minxx>double(x/y))
				minxx=double(x/y);
			j++;	
		}
		printf("%.9f\n",minxx);
	}
	return 0;
}
