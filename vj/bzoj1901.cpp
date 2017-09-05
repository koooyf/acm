#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=3e4;
struct Tree{
	int L,r,sum;
}tree[100*N];
int t,root[N],use[N],has[N],a[N],n,m,l[N],r[N],k[N];
char c[N];
int cnt=0;
void build(int L,int r,int &rt)
{
	rt=cnt++;
	tree[rt].sum=0;
	if(L==r) return ;
	int mid=(L+r)>>1;
	build(L,mid,tree[rt].L);
	build(mid+1,r,tree[rt].r);
}
void insert(int num,int L,int r,int &rt,int v)
{
	tree[cnt++]=tree[rt];
	rt=cnt-1;
	tree[rt].sum+=v;
	if(L==r) return ;
	int mid=(L+r)>>1;
	if(mid>=num)
		insert(num,L,mid,tree[rt].L,v);
	else
		insert(num,mid+1,r,tree[rt].r,v);
}
int lowbit(int x)
{
	return x&-x;
}
int size=0;
void add(int x,int v,int i,int L,int r)
{
	while(i<=n)
	{
		root[i]=root[i];
		insert(x,1,size,root[i],v);
		i+=lowbit(i);
	}
}
int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=tree[tree[use[x]].L].sum;
		x-=lowbit(x);	
	}
	return ans;
}
int query(int i,int j,int L,int r,int k)
{
	int d=sum(j)-sum(i);
	if(L==r)
		return L;
	int mid=(L+r)>>1;
	if(k<=d)
	{
		for(int x=j;x>0;x-=lowbit(x))
			use[x]=tree[use[x]].L;
		for(int x=i;x>0;x-=lowbit(x))
			use[x]=tree[use[x]].L;
		return query(i,j,L,mid,k);
	}
	else
	{
		for(int x=j;x>0;x-=lowbit(x))
			use[x]=tree[use[x]].r;
		for(int x=i;x>0;x-=lowbit(x))
			use[x]=tree[use[x]].r;
		return query(i,j,mid+1,r,k-d);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int tot=n;
		for(int i=1;i<=m;i++)
		{
			getchar();
			scanf("%c",&c[i]);
			if(c[i]=='Q')
				scanf("%d%d%d",&l[i],&r[i],&k[i]);
			else if(c[i]=='C')
			{
				scanf("%d%d",&l[i],&r[i]);
				tot++;
				a[tot]=r[i];		
			}
		}
		for(int i=1;i<=tot;i++)
			has[i]=a[i];
		sort(has+1,has+1+tot);
	    size=unique(has+1,has+tot+1)-(has+1);
//		printf("size=%d\n",size);
		for(int i=1;i<=tot;i++)
		a[i]=lower_bound(has+1,has+size+1,a[i])-has;
		cnt=0;
		build(1,size,root[0]);
		for(int i=1;i<=n;i++)
			root[i]=root[0];
		for(int i=1;i<=n;i++)
		{
			add(a[i],1,i,1,size);
		}
		tot=n;
		for(int i=1;i<=m;i++)
		{
			if(c[i]=='Q')
			{
				for(int j=r[i];j>0;j-=lowbit(j))
					use[j]=root[j];
				for(int j=l[i]-1;j>0;j-=lowbit(j))
					use[j]=root[j];
				printf("%d\n",has[query(l[i]-1,r[i],1,size,k[i])]);				
			}
			else
			{
				tot++;
				add(a[l[i]],-1,l[i],1,size);
				a[l[i]]=a[tot];
				add(a[l[i]],1,l[i],1,size);
			}
		}
	}
	return 0;
}
