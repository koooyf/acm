#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,father[1005];
void init(int x)
{
	for(int i=0;i<=x;i++)
		father[i]=i;
}
int getfather(int x)
{
	if(x!=father[x])
		father[x]=getfather(father[x]);
	return father[x];
}
void merge(int a,int b)
{
	int x=getfather(a);
	int y=getfather(b);
	if(x!=y)
	{
		father[x]=y;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init(n);
		int u,v;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			merge(u,v);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(father[i]==i)
				cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}
