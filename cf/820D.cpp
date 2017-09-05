#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
const int M = 1e6+10;
typedef long long ll;
int a[M],pre[M];
int abs(int a,int b)
{
	if(a>=b)
		return a-b;
	return b-a;
}
int main()
{
	int n;
	scanf("%d",&n);
	ll sum=0,minn;
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=abs(a[i],i);
		if(a[i]-i<=0) pre[0]++;
		else
			pre[a[i]-i]++;		
	}
	minn=sum;
	int cnt=pre[0],ans=0;
	for(int i=1;i<n;i++)
	{
		int pos=n-i+1;
		if(a[pos]-n<=0) 
			cnt--;
		if(a[pos]-pos<=0)
			pre[0]--;
		else
			pre[a[pos]-pos]--;
		pre[min(a[pos]-1+i,M-10)]++;
		sum+=cnt;
		sum-=(n-cnt-1);
		sum-=abs(a[pos]-n);
		sum+=abs(a[pos]-1);
		cnt+=pre[i];
		if(sum<minn)
		{
			minn=sum;
			ans=i;
		}
	
	}
	printf("%lld %d\n",minn,ans);
	return 0;
}
