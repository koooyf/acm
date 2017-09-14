#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct Edge{
	int v;
	int w;
	int next;
}e[100005];
int head[10005],edg_cnt=0,i,n,m,t;
map<int,int> qwq[10005];
void init()
{
	memset(head,-1,sizeof(head));
	edg_cnt=0;
}
void add(int u,int v,int w)
{
	e[edg_cnt]=(Edge){v,w,head[u]};
	head[u]=edg_cnt++;
}
int dis[10005],ans[10005];
int du[10005]={0},vis[10005],id=1;
vector<int> f[10005];
void topu()
{
	queue<int>q;
	memset(vis,0,sizeof(vis));
	id=1;
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)
	{
		if(du[i]==0)
		{
			ans[id]++;
			f[id].push_back(i);
			q.push(i);
			vis[i]=1;
		}
	}
	int tot=0;
	while(!q.empty())
	{
		tot++;
		int now=q.front();
		q.pop();
		for(int k=head[now];k!=-1;k=e[k].next)
		{
			du[e[k].v]--;
		}
		for(int i=1;i<=n;i++)
		{
			if(du[i]==0&&!vis[i])
			{
				ans[id+1]++;
				f[id+1].push_back(i);
				q.push(i);
				vis[i]=1;
			}
		}
		if(tot==ans[id])
		{
			id++;
			tot=0;
		}
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(dis,0,sizeof(dis));
		scanf("%d%d",&n,&m);
		init();
		memset(du,0,sizeof(du));
		for(int i=1;i<=n;i++) qwq[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			add(u,v,w);
			du[v]++;
			qwq[u][v]=w;
		}
		topu();
		for(int i=2;i<=id-1;i++)
		{
			for(int j=0;j<f[i].size();j++)
			{
				for(int k=0;k<f[i-1].size();k++)
				{
					if(qwq[f[i-1][k]][f[i][j]])
					{
						dis[i]=max(dis[i],dis[i-1]+qwq[f[i-1][k]][f[i][j]]);
					}
				}
			}
		}
		printf("%d\n",dis[id-1]);
	}
	return 0;
}
