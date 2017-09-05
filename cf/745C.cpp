#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
int father[1005];
int getfa(int x)
{
	if(x!=father[x])
		father[x]=getfa(father[x]);
		return father[x];
}
void mercy(int x,int y)
{
	x=getfa(x);
	y=getfa(y);
	if(x!=y)
		father[x]=y;
}

void init()
{
	for(int i=1;i<=1000;i++)
		father[i]=i;
}
int main()
{
	int n,m,k,u,v,ans[1005]={0},tree[1005]={0},c,vis[1005]={0};
	init();
	vector<int> q;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c);
		vis[c]=1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		int p=0;
		if(vis[v]==1)
		{
		p=ans[father[u]];
		if(father[u]==father[v])
			p=0;
		mercy(u,v);
		ans[father[v]]+=p+1;
		}
		else
		{
		p=ans[father[v]];
		if(father[u]==father[v])
			p=0;
		mercy(v,u);
		ans[father[u]]+=p+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(tree[father[i]]==0)
			q.push_back(father[i]);
		tree[father[i]]++;		
	}
	int num=0;
	for(int i=0;i<q.size();i++)
	{
		int tot=0;
		for(int j=tree[q[i]]-1;j>=1;j--)
			tot+=j;
		num+=(tot-ans[q[i]]);
	}
	int maxx=0,tot=0;
	for(int i=0;i<q.size();i++)
	{
		if(vis[q[i]]==1)
		{
			if(maxx<tree[q[i]])
				maxx=tree[q[i]];		
		}
	}
	for(int i=0;i<q.size();i++)
	{
		if(vis[q[i]]!=1)
		{
			tot+=(maxx*tree[q[i]]);
			maxx+=tree[q[i]];
		}
	}
	printf("%d\n",num+tot);
	return 0;
}
