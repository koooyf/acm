#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int N=1e5+50;
int n,m;
struct Tree{
int L,r,sum;
}tree[25*N];
struct point{
	int v;
	int id;
	bool operator < (const point &a)const
	{
		return v<a.v;
	}
	bool operator ==(const point &a)const
	{
		return v==a.v;
	}
}p[N];
int vis[N],cnt=0,root[N];
bool cmp(point a,point b)
{
	if(a.v<b.v)
		return 1;
	return 0;
}
void init()
{
	cnt=1;
	root[0]=0;
	tree[0].L=tree[0].r=tree[0].sum=0;
}
void build(int L,int r,int &rt)
{
	tree[cnt++].sum=0;
	rt=cnt-1;
	if(L==r) return ;
	int mid=(L+r)>>1;
	build(L,mid,tree[rt].L);
	build(mid+1,r,tree[rt].r);
}
void insert(int num ,int &rt,int L,int r)
{
	tree[cnt++]=tree[rt];
	rt=cnt-1;
	tree[rt].sum++;
	if(L==r) return ;
	int mid=(L+r)>>1;
	if(mid>=num)
		insert(num,tree[rt].L,L,mid);
	else
		insert(num,tree[rt].r,mid+1,r);
}
int query(int i,int j,int k,int L,int r)
{
	int d=tree[tree[j].L].sum-tree[tree[i].L].sum;
	if(L==r) return L;
	int mid=(L+r)>>1;
	if(d>=k) return query(tree[i].L,tree[j].L,k,L,mid);
	else return query(tree[i].r,tree[j].r,k-d,mid+1,r);
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i].v);
			p[i].id=i;
		}
		init();
		sort(p+1,p+n+1,cmp);		
		int tot=0;
		vis[p[1].id]=1;
		for(int i=2;i<=n;i++)
		{
			if(p[i-1].v==p[i].v)
			{
				tot++;
				vis[p[i].id]=i-tot;
			}
			else
				vis[p[i].id]=i-tot;
		}
		unique(p+1,p+n+1);	
//		for(int i=1;i<=n;i++)
//			printf("%d ",p[i].v);
//		printf("\n--------------------\n");
//		for(int i=1;i<=n;i++)
//			printf("%d ",vis[i]);
//		printf("\n--------------------\n");
		for(int i=1;i<=n;i++)
		{
			root[i]=root[i-1];
			insert(vis[i],root[i],1,n);
		}
		int l,r,k;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&l,&r,&k);
//			printf("%d\n",query(root[l-1],root[r],k,1,n-tot));
			printf("%d\n",p[query(root[l-1],root[r],k,1,n)].v);
		}
	}
	return 0;
}
