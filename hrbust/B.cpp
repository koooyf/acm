#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long a[100004],ans[100004],tot[100004],n;
long long maxx(long long x,long long y)
{
	if(x>=y)
		return x;
	else return y;
}
long long minxx(long long x,long long y)
{
	if(x<=y)
		return x;
	else return y;
}
int find(int l,int r)
{
	int m;
	while(l<=r)
	{
		 m=(l+r)/2;
		bool f=0;
		long long mx=ans[n]-ans[m];
		memset(tot,0,sizeof(tot));
		long long sum=0;
		for(int i=1;i<=m-1;i++)
		{
			sum+=a[i];
			tot[i+1]+=sum;
		}
		 sum=0;
		for(int i=m-1;i>=1;i--)
		{
			if(sum<tot[i+1])
				tot[i+1]=sum;
			sum+=a[i];
		}
		for(int i=1;i<=m;i++)
		{
			if(tot[i]>mx)
			{
				f=1;
				break;
			}
		}
		if(f==1)
			r=m-1;
		else
			l=m+1;
	}
	return m;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		memset(ans,0,sizeof(ans));
		long long qqq=0;
		for(int i=1;i<=n-1;i++)
		{
			scanf("%lld",&a[i]);
			qqq+=a[i];
			ans[i+1]+=qqq;
		}
		for(int i=1;i<=n;i++)
			printf("%lld ",ans[i]);
		printf("\n");
		int c=find(1,n);
		long long mx=ans[n]-ans[c],sum=0;
		for(int i=c-1;i>=1;i--)
		{
			if(sum<ans[i+1])
				ans[i+1]=sum;
			sum+=a[i];
		}
		for(int i=1;i<=c;i++)
		{
			if(ans[i]>mx)
				mx=ans[i];
		}
		c=c-1;
		long long mxx=ans[n]-ans[c];
		sum=0;
		for(int i=c-1;i>=1;i--)
		{
			if(sum<ans[i+1])
				ans[i+1]=sum;
			sum+=ans[i];
		}
		for(int i=1;i<=c;i++)
		{
			if(ans[i]>mxx)
				mxx=ans[i];
		}
		printf("%lld\n",minxx(mx,mxx));
	}
	return 0;
}
