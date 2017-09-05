#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int t,n,a[50050];
char s[100];
int tree[50050*4];
void  build(int node,int l,int r)
{
	if(l==r)
	{
		tree[node]=a[l];
		return ;
	}
	else
	{
		int m=(l+r)/2;
		build(2*node,l,m);
		build(2*node+1,m+1,r);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
int query(int node,int begin,int end,int l,int r)
{
	if(begin>r||end<l)
		return 0;
	if(begin>=l&&r>=end)
	{
			return tree[node];
	}
	int m=(begin+end)/2;
	int p1=query(2*node,begin,m,l,r);
	int p2=query(2*node+1,m+1,end,l,r);
	return p1+p2;	
}
void add(int node,int begin,int end,int p,int sum)
{
	if(begin==end)
	{
		tree[node]+=sum;
		return ;
	}
	int m=(begin+end)/2;
	if(p<=m)
		add(2*node,begin,m,p,sum);
	else
		add(2*node+1,m+1,end,p,sum);
	tree[node]=tree[2*node]+tree[2*node+1];
}
void sub(int node,int begin,int end ,int p,int sum)
{
	if(begin==end)
	{
		tree[node]-=sum;
		return ;
	}
	int m=(begin+end)/2;
	if(p<=m)
		sub(2*node,begin,m,p,sum);
	else
		sub(2*node+1,m+1,end,p,sum);
	tree[node]=tree[2*node]+tree[2*node+1];
}
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case %d:\n",i);
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		memset(tree,0,sizeof(tree));
		for(int j=1;j<=n;j++)
			scanf("%d",&a[j]);
		build(1,1,n);
		while(true)
		{
			int r,l;
			scanf("%s",s);
			if(strcmp("Query",s)==0)
			{
				scanf("%d%d",&l,&r);
				printf("%d\n",query(1,1,n,l,r));
			}
			else if(strcmp("Add",s)==0)
			{
				scanf("%d%d",&l,&r);
				add(1,1,n,l,r);
			}
			else if(strcmp("Sub",s)==0)
			{
				scanf("%d%d",&l,&r);
				sub(1,1,n,l,r);
			}
			else if(strcmp("End",s)==0)
				break;
		}
	}
	return 0;
}
