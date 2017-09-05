#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=1e5+5;
int father[2*N],n,m,dis[2*N],cnt=0;
void init(int x)
{
	for(int i=0;i<=x;i++)
		father[i]=i;
	memset(dis,0,sizeof(dis));
	cnt=0;
}
int getfather(int x)
{
	if(x!=father[x])
	{
		int t=father[x];
		father[x]=getfather(father[x]);
		dis[x]+=dis[t];
	}
	return father[x];
}
void merge(int a,int b,int w)
{
	int x=getfather(a);
	int y=getfather(b);
	if(x!=y)
	{
		if(x<y)
		{
			dis[y]=dis[a]+w-dis[b];
			father[y]=x;
		}
		else
		{
			dis[x]=dis[b]-w-dis[a];
			father[x]=y;
		}
	}
}
bool check(int a,int b)
{
	if(getfather(a)==getfather(b))
		return 1;
	return 0;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int u,v,w;
		init(n);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			u--;
			if(!check(u,v))
			{
				merge(u,v,w);
			}
			else
			{
				if(dis[v]-dis[u]!=w)
						cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
