#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
bool mp[3000][3000];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int x[5500],y[5500];
		memset(mp,0,sizeof(mp));
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			mp[x[i]+300][y[i]+300]=1;
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int a=x[i]-x[j],b=y[i]-y[j];
				if(mp[x[i]+b+300][y[i]-a+300]&&mp[x[j]+b+300][y[j]-a+300]) ans++;
				if(mp[x[i]-b+300][y[i]+a+300]&&mp[x[j]-b+300][y[j]+a+300]) ans++;
			}
		}
		printf("%lld\n",ans/4);
	}
	return 0;
}
