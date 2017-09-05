#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct two{
	int p,va;
};
#define N  4006
bool operator < (two a, two b)
{
	return (a.va>b.va);
}
int vis[1005],dis[1005],head[N],edg_cnt=0;
struct Edge{
	int v,w,next;
}edge[N];
void add(int u,int v,int w)
{
	edge[edg_cnt]=(Edge){v,w,head[u]};
	head[u]=edg_cnt++;
}
void dijkstra(int n)
{
	for(int i=1;i<n;i++)
		dis[i]=300000;
	memset(vis,0,sizeof(vis));
	priority_queue<two> q;
	dis[n]=0;
		two now;
	now.p=n,now.va=0;
	q.push(now);
	while(!q.empty())
	{
		two tmp=q.top();
		q.pop();
		int u=tmp.p;
		if(vis[u]) continue;
		vis[u]=1;
		for(int k=head[u];k!=-1;k=edge[k].next)
		{
			int vv=edge[k].v;
			if(dis[vv]>dis[u]+edge[k].w)
			{
				dis[vv]=dis[u]+edge[k].w;
				q.push((two){vv,dis[vv]});
			}	
		}
	}
}
int main()
{
	int t,nn;
	scanf("%d%d",&t,&nn);
	for(int i=0;i<N;i++)
		head[i]=-1;
    for(int i=1;i<=t;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dijkstra(nn);
	printf("%d\n",dis[1]);
	return 0;
}
