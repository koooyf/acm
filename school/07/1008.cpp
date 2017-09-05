#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
struct point{
	long long  x;
	long long  y;
	long long  v;
}p[200000];
bool cmp(point a, point b)
{
	if(a.x*b.y-a.y*b.x<0)
		return 1;
	return 0;
}
bool check(int k,int i)
{
	if(p[i].x*p[k].y-p[i].y*p[k].x<0)
		return 1;
	return 0;
}
int  find(int L,int r,int i)
{
	while((r-L)>1)
	{
		int mid=(L+r)>>1;
		if(check(mid,i))
			L=mid;
		else 
			r=mid;
	}
	int ans=check(L,i)?r:L;
	if(check(r,i)) return r+1; else return ans;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long ans=0,up=0,down=0,max1=0,max2=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].v);
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			p[i+n].x=p[i].x;
			p[i+n].y=p[i].y;
			p[i+n].v=p[i].v;
		}
	  	int cnt1=find(2,n,1);
		for(int i=2;i<cnt1;i++)
		{
			down+=p[i].v;
		}
		max1=p[1].v*down;
		for(int i=cnt1;i<=n;i++)
		{
			up+=p[i].v;
		}
		max2=p[1].v*up;
		ans=down*up+max(max1,max2);	
	//	printf("%d %lld\n",cnt1,ans);
		for(int i=2;i<=n;i++)
		{
			int cnt2=find(i+1,n-1+i,i);
			for(int j=cnt1;j<cnt2;j++)
			{
				up-=p[j].v;
				down+=p[j].v;
			}
			down-=p[i].v;
			up+=p[i-1].v;
	//		printf("cnt2=%d cnt1=%d\n",cnt2,cnt1);
			max1=p[i].v*down;
			max2=p[i].v*up;
			ans=max(ans,down*up+max(max1,max2));
	//		printf("%lld %d\n",ans,i);
			cnt1=cnt2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
