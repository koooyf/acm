#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,father[30005];
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
		father[x]=y;
}
int p[30005];
int main()
{
	while(true)
	{
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)
			break;
		int cnt=0;
		init(n);
		for(int i=1;i<=m;i++)
		{
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
			{
				scanf("%d",&p[j]);
			}
			sort(p+1,p+k+1);
			for(int j=2;j<=k;j++)
				merge(p[j-1],p[j]);
		}
		for(int i=0;i<n;i++)
		{
			getfather(i);
		}
		for(int i=0;i<n;i++)
		{
			if(father[i]==father[0])
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
