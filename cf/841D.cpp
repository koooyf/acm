#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=3e5+50;
struct Edge{
	int v;
	int id;
	int next;
}edge[2*N];
struct P{
	int u;
	int id;
};
int n,m,d[N];
int head[N],edg_cnt=0;
P fa[N];
void add(int u,int v,int id)
{
	edge[edg_cnt]=(Edge){v,id,head[u]};
	head[u]=edg_cnt++;
}
int select[N],vis[N];
void dfs(int u)
{
	for(int k=head[u];k!=-1;k=edge[k].next)
	{
		int v=edge[k].v;
		int id=edge[k].id;
		if(vis[v]) continue;
		vis[v]=1;
		fa[v]=(P){u,id};
		dfs(v);
		if(d[v]==1)
		{
			d[v]=0;
			select[id]^=1;
			if(d[u]!=-1)
				d[u]^=1;				
		}
	}
}
int main()
{		
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(select,0,sizeof(select));
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i]==-1)
		{
			flag=i;
		}
	}
	int u,v;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v,i);
		add(v,u,i);
	}
	vis[1]=1;
	dfs(1);
	if(d[1]==1)
	{
		if(!flag)
		{
			printf("-1\n");
			return 0;
		}
		else
		{
			while(flag!=1)
			{
				select[fa[flag].id]^=1;
				flag=fa[flag].u;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
		if(select[i])
			ans++;
	printf("%d\n",ans);
	for(int i=1;i<=m;i++)
	{
		if(select[i])
			printf("%d ",i);
	}
	printf("\n");
	return 0;
}
