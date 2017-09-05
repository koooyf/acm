#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 2000000009
struct node{
	int l,r,v,type;
	node(){}
	node(int ll,int rr, int vv,int ttype):l(ll),r(rr),v(vv),type(ttype){}
};
bool cmp(node b,node c)
{
	if(b.l==c.l)
		return b.type<c.type;
	return b.l<c.l;
}
vector<node> a;
int sum[200006];
int main()
{
	int n,x,left,rrr,cost;
	scanf("%d%d",&n,&x);
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&left,&rrr,&cost);
		a.push_back(node(left,rrr,cost,-1));
		a.push_back(node(rrr,left,cost,1));
	}
	sort(a.begin(),a.end(),cmp);
	int ans=maxn;
	for(int i=0;i<a.size();i++)
	{
		if(a[i].type==-1)
		{
			int temp=a[i].r-a[i].l+1;
			if(temp>=x||!sum[x-temp])	continue;
			ans=min(ans,sum[x-temp]+a[i].v);
		}
		else
		{
			if(!sum[a[i].l-a[i].r+1]||sum[a[i].l-a[i].r+1]>a[i].v)
				sum[a[i].l-a[i].r+1]=a[i].v;
		}
	
	}
	if(ans!=maxn)
		printf("%d\n",ans);
	else
		printf("-1\n");
	return 0;
}
