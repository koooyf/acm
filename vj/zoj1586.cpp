#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int vis[2000],c[2000],t,n,mp[2000][2000],cost[2000];
int prim()
{
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cost[i]=mp[1][i];
	}
	for(int i=2;i<=n;i++)
	{
		int minn=1000000000;
		int id;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&minn>cost[j])
			{
				minn=cost[j];
				id=j;
			}
		}
		vis[id]=1;
		ans+=minn;
		for(int j=1;j<=n;j++)
		{
			if(cost[j]>mp[id][j])
			{
				cost[j]=mp[id][j];
			}
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
					mp[i][j]+=c[i];
					mp[j][i]+=c[i];
			}
		}
		int w;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&w);
				mp[i][j]+=w;
			}
		printf("%d\n",prim());
	}
	return 0;
}
