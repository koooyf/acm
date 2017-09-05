#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long  a[1000000],b[1000000],c[1000000],d[1000000];
long long ersearch(long long first,long long  end,long long tot)
{
	long long middle=0;
	while(first<=end)
	{
		 middle=(first+end)/2;
		if(d[middle]<=tot)
		{
			first=middle+1;
		}
		else if(d[middle]>tot)
		{
			end=middle-1;
		}
	}
	return middle;
}
long long minx(long long x,long long y)
{
	if(x<=y) return x;
	else return y;
}
int main()
{
	long long  n,m,k,x,s;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	scanf("%I64d%I64d",&x,&s);
	long long mn;
	mn=n*x;
	for(long long i=1;i<=m;i++)
		scanf("%I64d",&a[i]);
	for(long long  i=1;i<=m;i++)
		scanf("%I64d",&b[i]);
	for(long long i=1;i<=k;i++)
	 	scanf("%I64d",&c[i]);
	for(long long i=1;i<=k;i++)
		scanf("%I64d",&d[i]);
	long long middle=ersearch(1,k,s);
	if(middle==1)
	{
		if(d[middle]<=s)
			mn=minx(mn,(n-c[middle])*x);
	}
	else if(middle==k)
	{
		if(d[middle]<=s)
			mn=minx(mn,(n-c[middle])*x);
		else 
			mn=minx(mn,(n-c[middle-1])*x);
	}
	else
	{
		if(d[middle]<=s)
		mn=minx(mn,(n-c[middle])*x);
		else
		mn=minx(mn,(n-c[middle-1])*x);
	}
	for(long long i=1;i<=m;i++)
	{
		if(b[i]<=s)
		{
			long long middle=ersearch(1,k,s-b[i]);
			if(middle==1)
			{
				if(d[middle]<=s-b[i])
				{
					mn=minx(mn,(n-c[middle])*a[i]);
				}
				else 
					mn=minx(mn,a[i]*n);
			}
			else if(middle==k)
			{
				if(d[middle]<=s-b[i])
					mn=minx(mn,(n-c[middle])*a[i]);
				else 
					mn=minx(mn,(n-c[middle-1])*a[i]);
			}
			else
			{
				if(d[middle]<=s-b[i])
				mn=minx(mn,(n-c[middle])*a[i]);
				else
				mn=minx(mn,(n-c[middle-1])*a[i]);
			}		
		}
	}
	printf("%I64d\n",mn);
	return 0;
}
