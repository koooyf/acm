#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,vis[30],mp[30][30],lowcost[30];
void init()
{
	memset(mp,0,sizeof(mp));
}
int Prim()
{
	int ans=0,id=0;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	for(int i=1;i<=n;i++)
		lowcost[i]=mp[1][i];
	for(int i=2;i<=n;i++)
	{
		int minn=1000000000;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&lowcost[j]<minn)
			{
				minn=lowcost[j];
				id=j;
			}
		}
		vis[id]=1;
		ans+=minn;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&lowcost[j]>mp[id][j])
			{
				lowcost[j]=mp[id][j];
			}
		}	
	}
	return ans;
}
int main()
{
	while(true)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<30;i++)
			for(int j=0;j<30;j++)
				mp[i][j]=1000000000;
		for(int i=1;i<n;i++)
		{
			char c[2],cc[2];
			int m,cost;
			scanf("%s",c);
			scanf("%d",&m);
			for(int j=1;j<=m;j++)
			{
				scanf("%s",cc);
				scanf("%d",&cost);
				mp[c[0]-'A'+1][cc[0]-'A'+1]=cost;
				mp[cc[0]-'A'+1][c[0]-'A'+1]=cost;
			}
		}
		int ans=Prim();
		printf("%d\n",ans);
	}
	return 0;
}
