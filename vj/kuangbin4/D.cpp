#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
int edg_cnt=0,n,m,x,vis[1005],dis[1005],head[1005];
struct Edge{
	int v,w,next;
}edge[100005];
struct pr{
	int point,value;
};
bool operator < (pr a,pr b)
{
	return (a.value>b.value);
}
void add(int u,int v,int w)
{
	edge[edg_cnt]=(Edge){v,w,head[u]};
	head[u]=edg_cnt++;
}
void dijkstra(int s)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(i!=s)
			dis[i]=2000000000;
	}
	dis[s]=0;
	priority_queue<pr> q;
	q.push((pr){s,0});
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
			if(dis[v]>dis[u]+edge[k].w)
			{
				dis[v]=dis[u]+edge[k].w;
				q.push((pr){v,dis[v]});
			}
		}
	}
}
int main()
{
	while(scanf("%d%d%d",&n,&m,&x)!=EOF)
	{
		for(int i=0;i<=n;i++)
			head[i]=-1;
		edg_cnt=0;
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);	
		}

	
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			dijkstra(i);
			int sum=dis[x];
			dijkstra(x);
			sum+=dis[i];
			if(maxx<sum)
			{
				maxx=sum;
			}
		}
		printf("%d\n",maxx);
	}
	return 0;
}
