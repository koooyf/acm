#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<iostream>
using namespace std;
int n,edg_cnt=0,head[300],vis[300],ca=0;
double x[300],y[300],dis[300];
struct pr{
	int point;
	double value;
};
bool operator < (pr a,pr b)
{
	return (a.value>b.value);
}
struct Edge{
	int v;
	double w;
	int next;
}edge[500000];
void add(int u,int v,double w)
{
	edge[edg_cnt]=(Edge){v,w,head[u]};
	head[u]=edg_cnt++;	
}
void dijkstra()
{
	memset(vis,0,sizeof(vis));
	priority_queue <pr> q;
	for(int i=2;i<=n;i++)
		dis[i]=2000000000;
		dis[1]=0;
	q.push((pr){1,0.0});
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
			if(dis[v]>max(dis[u],edge[k].w))
			{
				dis[v]=max(dis[u],edge[k].w);
			//	printf("%lf %d %d\n",dis[v],u,v);
				q.push((pr){v,dis[v]});
			}
//			printf("%lf %d %d\n",dis[v],u,v);
		}
	}	
}
int main()
{
	while(true)
	{
		ca++;
		scanf("%d",&n);
		if(n==0)
			break;
		for(int i=0;i<=n;i++)
			head[i]=-1;
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				double sum=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				if(i!=j)
				{
				add(i,j,sum);
				add(j,i,sum);	
				}			
			}
		}
		dijkstra();
		printf("Scenario #%d\n",ca);
		printf("Frog Distance = %.3f\n\n",dis[2]);
	}
	return 0;
}
