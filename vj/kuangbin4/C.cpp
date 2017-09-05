#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<iostream>
using namespace std;
int ca,n,m,a,b,c,vis[1050],dis[1050],head[1050],edg_cnt=0;
struct Edge{
	int v,w,next;
}edge[3000000];
struct pr{
	int point,value;
};
void add(int u,int v,int w)
{
	edge[edg_cnt]=(Edge){v,w,head[u]};	
	head[u]=edg_cnt++;
}
bool operator < (pr x, pr y)
{
	return (x.value>y.value);
}
void dijkstra()
{
	memset(vis,0,sizeof(vis));
	priority_queue<pr> q;
	for(int j=2;j<=n;j++)
		dis[j]=-1;
	dis[1]=2000000000;
	q.push((pr){1,0});	
	while(!q.empty())
	{
		pr t=q.top();
		q.pop();
		int u=t.point;
		if(vis[u]) continue;
		vis[u]=1;
		for(int k=head[u];k!=-1;k=edge[k].next)
		{
			int v=edge[k].v;
			if(dis[v]<min(dis[u],edge[k].w))
			{
				dis[v]=min(dis[u],edge[k].w);
				q.push((pr){v,dis[v]});
			}
		}
	}
}	
int main()
{
	scanf("%d",&ca);
	for(int i=1;i<=ca;i++)
	{
		scanf("%d%d",&n,&m);
		edg_cnt=0;
		for(int k=0;k<=n;k++)
			head[k]=-1;
		for(int k=1;k<=m;k++)
		{
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
		}
		dijkstra();
		printf("Scenario #%d:\n",i);
		printf("%d\n\n",dis[n]);
	}
	return 0;
}
