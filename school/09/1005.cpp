#include<cstdio>
#include<stack>
#include<queue>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
const int N=10000;
struct Edge{
	int v;
	int next;
}edge[N];
int head[2000],edg_cnt=0,dfn[N],low[N],sccno[N],step,scc_cnt=0,ip;
void init()
{
	ip=0;
	edg_cnt=0;
	memset(head,-1,sizeof(head));
}
void add(int u,int v)
{
	edge[edg_cnt]=(Edge){v,head[u]};
	head[u]=edg_cnt++;
}
vector<int> scc[N];
stack<int> s;
void dfs(int u)
{
	dfn[u]=low[u]=++step;
	s.push(u);
	for(int k=head[u];k!=-1;k=edge[k].next)
	{
		int v=edge[k].v;
		if(!dfn[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!sccno[v])
		{
			low[u]=min(low[u],low[v]);
		}
	}
	if(low[u]==dfn[u])
	{
		scc_cnt+=1;
		scc[scc_cnt].clear();
		while(true)
		{
			int x=s.top();
			s.pop();
			if(sccno[x]!=scc_cnt) scc[scc_cnt].push_back(x);
			sccno[x]=scc_cnt;
			if(x==u)
				break;
		}
	}
}
void tarjan(int n)
{
	memset(sccno,0,sizeof(sccno));
	memset(dfn,0,sizeof(dfn));
	step=scc_cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])dfs(i);
	}
}
int du[N]={0},vis[N];
void topu()
{
	queue<int>q;
	int ans=0;
	bool f=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=scc_cnt;i++)
	{
		if(du[i]==0)
		{
			ans++;
			q.push(i);
			vis[i]=1;
		}
	}
	if(ans>=2)
		f=1;
	while(!q.empty())
	{
		ans=0;
		int now=q.front();
		q.pop();
		for(int k=head[now];k!=-1;k=edge[k].next)
			du[edge[k].v]--;
		for(int i=1;i<=scc_cnt;i++)
		{
			if(du[i]==0&&!vis[i])
			{
				ans++;
				q.push(i);
				vis[i]=1;
			}
		}
		if(ans>=2)
			f=1;
	}
	if(f)
		printf("Light my fire!\n");
	else
		printf("I love you my love and our love save us!\n");
}
int main()
{
	int t,n,m,u[N],v[N];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(du,0,sizeof(du));
		init();
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u[i],&v[i]);
			add(u[i],v[i]);
		}
		tarjan(n);
		for(int i=1;i<=scc_cnt;i++)
		{
			for(int j=0;j<scc[i].size();j++)
				printf("%d ",scc[i][j]);
			printf("\n");
		}
		init();
		for(int i=1;i<=m;i++)
		{
			if(sccno[u[i]]!=sccno[v[i]])
			{
				add(sccno[u[i]],sccno[v[i]]);
				du[sccno[v[i]]]++;
			}
		}
//		for(int i=1;i<=scc_cnt;i++)
//			printf("%d ",du[i]);
//		printf("\n");
		topu();
	}
	return 0;
}
