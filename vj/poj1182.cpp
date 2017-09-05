#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int father[50005],n,m,value[50005];
void init(int x)
{
	for(int i=0;i<=x;i++)
		father[i]=i;
	for(int i=0;i<=x;i++)
		value[i]=0;
}
int getfather(int x)
{
	if(x==father[x])
		return father[x];
	int y=getfather(father[x]);
	value[x]=(value[x]+value[father[x]])%3;
	return father[x]=y;
}
int merge(int a,int b,int w)
{
	int x=getfather(a);
	int y=getfather(b);
	if(x==y)
	{
		if((value[a]-value[b]+3)%3==w-1)
			return 0;
		return 1;
	}
	father[x]=y;
	value[x]=(-value[a]+w-1+value[b]+3)%3;
	return 0;
}
int main()
{
		scanf("%d%d",&n,&m);
		init(n);
		int u,v,id,cnt=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&id,&u,&v);
			if((id==2&&u==v))
				cnt++;
			else if(u>n||v>n)
				cnt++;
			else
				cnt+=merge(u,v,id);
		}
		printf("%d\n",cnt);
	return 0;
}
