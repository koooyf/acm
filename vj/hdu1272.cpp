#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int father[N];
void init()
{
	for(int i=0;i<=100001;i++)
		father[i]=i;
}
int getfather(int x)
{
	if(x!=father[x])
		father[x]=getfather(father[x]);
	return father[x];
}
bool check(int a,int b)
{
	return getfather(a)==getfather(b);
}
void merge(int a,int b)
{
	int x=getfather(a);
	int y=getfather(b);
	if(x!=y)
		father[x]=y;
}
int main()
{
	int u,v;
	int vis[N];
	while(true)
	{
		vector<int>a;
		a.clear();
		bool flag=0,f=0;
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&u,&v);
		if(u==-1&&v==-1)
			break;
//		if(u==0&&v==0)
//		{
//			printf("Yes\n");
//			continue;
//		}
		init();
		merge(u,v);
		vis[u]=1;
		a.push_back(u);
		vis[v]=1;
		a.push_back(v);
		while(true)
		{
			scanf("%d%d",&u,&v);
			if(u==0&&v==0)
				break;
			if(check(u,v))
				flag=1;
			merge(u,v);
			if(!vis[u])
			{
				vis[u]=1;
				a.push_back(u);
			}
			if(!vis[v])
			{
				vis[v]=1;
				a.push_back(v);
			}
		}
		getfather(a[0]);
		int t=father[a[0]];
		for(int i=1;i<a.size();i++)
		{
			getfather(a[i]);
			if(father[a[i]]!=t)
				f=1;
		}
		if(!flag&&!f)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
