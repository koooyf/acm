#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int father[20005],number[20005],cnt[5050]={0};
long long sum=0;
void init(int x)
{
	for(int i=0;i<=x;i++)
	{
		father[i]=i;
		number[i]=1;
	}
}

int getfather(int x)
{
	if(x!=father[x])
		father[x]=getfather(father[x]);
	return father[x];
}
void merge(int a,int b)
{
	a=getfather(a);
	b=getfather(b);
	if(a!=b)
	{
	int x=number[a];
	int y=number[b];
	sum-=x*(x-1);
	sum-=y*(y-1);
	number[a]+=number[b];
	number[b]=0;
	sum+=number[a]*(number[a]-1);
	number[b]=0;
	father[b]=a;
	}
}
struct edge{
	int u,v,w;
	edge(int u,int v,int w) : u(u),v(v),w(w){}
	friend bool operator < (const edge &x,const edge &y)
	{
		return x.w<y.w;
	}
};
struct qqq{
	int v;int id;
	friend bool operator < (const qqq &x,const qqq &y)
	{
		return x.v<y.v;
	}
};
vector<edge> e;
qqq qq[5050];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,q;
		scanf("%d%d%d",&n,&m,&q);
		sum=0;
		memset(number,0,sizeof(number));
		init(n);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			e.push_back(edge(u,v,w));
		}
		sort(e.begin(),e.end());
		for(int i=1;i<=q;i++)
		{
			int d;
			scanf("%d",&d);
			qq[i].v=d;qq[i].id=i;
		}
		sort(qq+1,qq+1+q);
		int ans=0;
		for(int i=1;i<=q;i++)
		{
			while(ans<m&&e[ans].w<=qq[i].v)
			{
				merge(e[ans].u,e[ans].v);
				ans++;
			}
			 cnt[qq[i].id]=sum;
		}
		for(int i=1;i<=q;i++) printf("%d\n",cnt[i]);
		e.clear();
		sum=0;
	}
	return 0;
}
