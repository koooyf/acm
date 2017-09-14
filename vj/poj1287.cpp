#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int mp[100][100],vis[100],cost[100];
int prim()
{
	int ans=0;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	for(int i=1;i<=n;i++)
		cost[i]=mp[1][i];
	for(int i=2;i<=n;i++)
	{
		int minn=1000000000;
		int id;
		for(int j=1;j<=n;j++)
		{
			if(cost[j]<minn&&!vis[j])
			{
				minn=cost[j];
				id=j;
			}
		}
		vis[id]=1;
		ans+=minn;
//		printf("%d %d\n",id,cost[id]);
		for(int j=1;j<=n;j++)
		{
			if(cost[j]>mp[id][j])
				cost[j]=mp[id][j];
		}
	}
	return ans;
}
int main()
{
	while(true)
	{
		scanf("%d",&n);
		if(!n)
			break;
		scanf("%d",&m);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
				mp[i][j]=1000000000;
		}
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(mp[u][v]>w)mp[u][v]=w;
			if(mp[v][u]>w)mp[v][u]=w;
		}
		int ans=prim();
		printf("%d\n",ans);
	}
	return 0;
}
