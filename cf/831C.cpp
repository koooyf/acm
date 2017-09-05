#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int h[20000010];
const int base=1e7+5;
int main()
{
	int k,n,sum[2005]={0},b[2050],cnt=0;
	scanf("%d%d",&k,&n);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
		h[base+sum[i]]=1;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(sum+1,sum+k+1);
	k=unique(sum+1,sum+k+1)-sum-1;
	for(int i=1;i<=k;i++)
	{
		int num=0,s=b[1]-sum[i];
		for(int j=1;j<=n;j++)
		{
			num+=h[b[j]-s+base];
		}
		if(num==n) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
