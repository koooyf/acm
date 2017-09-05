#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long h[100005],hh[100005];
int t,n,k,q;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int sum;
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++)
			scanf("%lld",&h[i]);
		for(int i=1;i<=q;i++)
		{
			int x,y;
			long long ans=1;
			scanf("%d%d",&x,&y);
			for(int j=x;j<=y;j++)
			{
				hh[j]=ans;
				ans+=k;
			}
			 sum=0;
			 int mx=-1;
			for(int j=x;j<=y;j++)
			{
				if(hh[j]<=h[j])
				{
					sum++;
					mx=max(mx,sum);
				}
				else
					sum=0;
			}
			printf("%d\n",mx);
		}
	}
	return 0;
}
