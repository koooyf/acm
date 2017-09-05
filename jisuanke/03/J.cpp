#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[200005],t,n,bit[200005]={0},b[200005]={0};
typedef long long ll;
struct node{
	int s;
	int w;
}ne[200005];
int lowbit(int x)
{
	return x&(-x);
}
ll sum(int x)
{
	ll ans=0;
	while(x>0)
	{
		ans+=bit[x];
		x-=lowbit(x);
	}
	return ans;
}
void swap(int &x,int &y)
{
	int t;
	t=x;
	x=y;
	y=t;
}
void qsort(int L,int r)
{
	int x,i,j;
	i=L;
	j=r;
	x=b[(L+r)>>1];
	do{
		while(b[i]<x) i++;
		while(b[j]>x) j--;
		if(i<=j)
		{
			swap(b[i],b[j]);
			swap(ne[i].s,ne[j].s);
			swap(ne[i].w,ne[j].w);
			i++;
			j--;
		}
	}while(i<=j);
	if(L<j) qsort(L,j);
	if(i<r) qsort(i,r);
}
void add(int x,int v)
{
	while(x<=2*n)
	{
		bit[x]+=v;
		x+=lowbit(x);
	}
}
struct point
{
	int x;
	int y;
}p[100005];
bool cmp(point a, point b)
{
	if(a.x<b.x)
		return 1;
	if(a.x==b.x&&a.y<b.y)
		return 1;
	return 0;
}
void make()
{
	int j=0;
	for(int i=1;i<=n;i++)
	{
		b[++j]=p[i].x;
		ne[j].s=1;
		ne[j].w=i;
		b[++j]=p[i].y;
		ne[j].s=2;
		ne[j].w=i;
	}
    qsort(1,2*n);
	j=0;
	for(int i=1;i<=2*n;i++)
	{
		if(ne[i].s==1)
		{
			if(b[i]==b[i-1])
			{
				j++;
				p[ne[i].w].x=i-j;
			}
			else
				p[ne[i].w].x=i-j;
		}
		else
		{
			if(b[i]==b[i-1])
			{
				j++;
				p[ne[i].w].y=i-j;
			}
			else
				p[ne[i].w].y=i-j;
		}
//		printf("%d\n",b[i]);
	}
}
int main()
{
	scanf("%d",&t);
	int ca=0;
	while(t--)
	{
		ca++;
		ll ans=0;
		b[0]=-1;
		memset(bit,0,sizeof(bit));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		sort(p+1,p+n+1,cmp);
//		for(int i=1;i<=n;i++)
//			printf("%d %d\n",p[i].x,p[i].y);
		make();
		for(int i=1;i<=n;i++)
		{
			add(p[i].y,1);
			ll cnt1=sum(p[i].y);
			ll cnt2=sum(2*n);
			ans+=abs(cnt1-cnt2);
//			printf("%lld %lld\n",cnt2,cnt1);
//			printf("%d %d\n",p[i].x,p[i].y);
		}
		printf("Case #%d: %lld\n",ca,ans);
	}
	return 0;
}
