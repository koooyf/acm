#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+50;
int n,m,root[N],cnt;
struct Tree{
	int L;
	int r;
	int sum;
}tree[25*N];
struct point{
	int v;
	int id;
	bool operator < (const point &a) const
	{
		return v<a.v;
	}
	bool operator == (const point &a)const 
	{
		return v==a.v;
	}
}p[N];
void init()
{
	cnt=1;
	root[0]=0;
	tree[0].L=tree[0].r=tree[0].sum=0;
}
void insert(int num,int L,int r,int &rt)
{
	tree[cnt++]=tree[rt];
	rt=cnt-1;
	tree[rt].sum++;
	if(L==r) return ;
	int mid=(L+r)>>1;
	if(mid>=num) insert(num,L,mid,tree[rt].L);
	else insert(num,mid+1,r,tree[rt].r);
}
int ans=0;
int query(int i,int lk,int k,int L,int r)
{
	int mid=(L+r)>>1;
	if(k<L||lk>r) return 0;
	if(L>=lk&&r<=k)
		return tree[i].sum;
//	if(mid<=k)
		ans=(query(tree[i].L,lk,k,L,mid)+query(tree[i].r,lk,k,mid+1,r));
	return ans;
}
bool cmp(point a,point b)
{
	return a.v<b.v;
}
int vis[N];
bool f[N];
int tot=0;
bool check(int x,int k)
{
	if(p[x].v>k)
		return 1;
	else return 0;
}
int find(int L,int r,int k)
{
	while(r-L>1)
	{
		int mid=(L+r)>>1;
		if(check(mid,k))
			r=mid;
		else
			L=mid;
	}
	int ans=check(L,k)?L:r;
	if(!check(r,k)) return n-tot+1;
	else
		return ans;
}
int main()
{	
	int t,ca=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i].v);
			p[i].id=i;
		}
		init();
		sort(p+1,p+n+1,cmp);
		vis[p[1].id]=1;
		 tot=0;
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
		//for(int i=1;i<=n;i++)
		//	printf("%d ",p[i].v);
	//	printf("\ntot=%d\n------------------------\n",tot);
	//	for(int i=1;i<=n;i++)
	//		printf("%d ",vis[i]);
	//	printf("\n----------------------------\n");
//		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
				root[i]=root[i-1];
				insert(vis[i],1,n-tot,root[i]);
		}
		int l,r,k;
		ca++;
		printf("Case %d:\n",ca);
		for(int i=1;i<=m;i++)
		{
			ans=0;
			scanf("%d%d%d",&l,&r,&k);
			int m=find(1,n-tot,k)-1;
		//	printf("m=%d\n",m);
//			m=5;
//			printf("Case %d:\n",ca);
			printf("%d\n",query(root[r+1],1,m,1,n-tot)-query(root[l],1,m,1,n-tot));
//			printf("--------------------------\n");
//			printf("%d\n",query(root[l],1,m,1,n-tot));
		}
	}
	return 0;
}
