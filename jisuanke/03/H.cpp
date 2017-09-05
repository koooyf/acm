#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long a[20000],b[20000];
void swap(long long &x,long long &y)
{
	long t;
	t=x;
	x=y;
	y=t;
}
void qsort(int L,int r)
{
	int i,j,x,y;
	i=L;
	j=r;
	x=a[(L+r)>>1];
	y=b[(L+r)>>1];
	do{
		while(a[i]<x||(a[i]==x&&b[i]>y)) i++;
		while(a[j]>x||(a[j]==x&&b[j]<y)) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(L<j)qsort(L,j);
	if(i<r)qsort(i,r);
	return ;
}
int main()
{
	int n;
	long long k;
	while(scanf("%d%lld",&n,&k)!=EOF)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",&b[i],&a[i]);
		qsort(1,n);
		for(int i=1;i<=n;i++)
		{
			if(k>=a[i])
			{
				k+=b[i];
				ans++;
			}
			printf("%lld %lld\n",a[i],b[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
