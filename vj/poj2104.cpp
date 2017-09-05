#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+50;
int n,m,a[N];
struct Node{
int L,r,sum;
}node[25*N];
struct point{
	int v,id;
}p[N];
int root[N]={0},vis[N]={0};
bool cmp(point x, point y)
{
	if(x.v<y.v)
		return 1;
	return 0;
}
int cnt;
void init()
{
	cnt=1;
	root[0]=0;
	node[0].L=node[0].r=node[0].sum=0;
}
void insert(int num,int &rt,int L,int r)
{
	node[cnt++]=node[rt];
	rt=cnt-1;
	node[rt].sum++;
	if(L==r) return ;
	int mid=(L+r)>>1;
	if(mid>=num) insert(num,node[rt].L,L,mid);
	else insert(num,node[rt].r,mid+1,r);
}
int query(int i,int j,int k,int L,int r)
{
	int d=node[node[j].L].sum-node[node[i].L].sum;
	if(L==r) return L;
	int mid=(L+r)>>1;
	if(k<=d) return query(node[i].L,node[j].L,k,L,mid);
	else
	return query(node[i].r,node[j].r,k-d,mid+1,r);
}
int main()
{	
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			p[i].v=a[i],p[i].id=i;
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++)
			vis[p[i].id]=i;
		init();
		for(int i=1;i<=n;i++)
		{
			root[i]=root[i-1];
			insert(vis[i],root[i],1,n);
		}
		int l,r,k;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",p[query(root[l-1],root[r],k,1,n)].v);
		}
	}
	return 0;
}
