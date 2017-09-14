#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,mp[200][200];
int vis[200],tot=0;
int prim()
{
	int ans=0;
	vis[1]=1;
	for(int k=2;k<=n;k++)
	{
		int minn=1000000000;
		int id;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(minn>mp[i][j]&&vis[i]&&!vis[j])
				{
					minn=mp[i][j];
					id=j;
				}
			}
		}
		vis[id]=1;
		if(minn!=1000000000)
		ans+=minn;
	}
	return ans;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		tot=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mp[i][j]);
		int u,v;
		scanf("%d",&m);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			mp[u][v]=0;
			mp[v][u]=0;
		}
		int ans=prim();
			printf("%d\n",ans);
	}
	return 0;
}
