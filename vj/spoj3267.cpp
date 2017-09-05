#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=3e4+50;
int n,a[N],has[N],root[N],cnt;
struct Tree{
	int L;
	int r;
	int sum;
}tree[25*N];
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
int ans;
int query(int i, int j,int L,int r,int start,int end)
{
	if(L>end||start>r) return 0;
	int mid=(L+r)>>1;
	if(L>=start&&r<=end) return tree[j].sum-tree[i].sum;
    ans=(query(tree[i].L,tree[j].L,L,mid,start,end)+query(tree[i].r,tree[j].r,mid+1,r,start,end));
	return ans;
}
int m;
int pre1[N],vis[N],pre[N];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			has[i]=a[i];
		}
		init();
		sort(has+1,has+n+1);
		memset(pre1,0,sizeof(pre1));
		memset(pre,0,sizeof(pre));
		int size=unique(has+1,has+n+1)-has-1;	
		for(int i=1;i<=n;i++)
			a[i]=lower_bound(has+1,has+size+1,a[i])-has-1;
		for(int i=1;i<=n;i++)	
		{
			pre[a[i]]=pre1[a[i]];
			pre1[a[i]]=i;
			root[i]=root[i-1];
			insert(pre[a[i]],0,n,root[i]);
		}
		scanf("%d",&m);
		int l,r;
		for(int i=1;i<=m;i++)
		{
			ans=0;
			scanf("%d%d",&l,&r);
			printf("%d\n",query(root[l-1],root[r],0,n,0,l-1));
		}
	}
	return 0;
}
