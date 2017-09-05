#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=1e6+30;
struct point{
	int x;
	bool flag;
	int id;
}p[N];
bool cmp(point a,point b)
{
	return a.x<b.x;
}
int main()
{
	int n,a[N],b[N],vis[N];
	while(scanf("%d",&n)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&b[i]);
		for(int i=0;i<n;i++)
		{
			p[i].x=a[i]-b[i];
			p[i].id=i;
		}
		for(int i=1;i<n;i++)
		{
			if(p[i].x>=0)
				p[i-1].flag=1;
			else
				p[i-1].flag=0;
		}
		if(p[0].x>=0)
			p[n-1].flag=1;
		else
			p[n-1].flag=0;
		for(int i=0;i<n;i++)
		{
			vis[p[i].x]++;
		}
		int minx=100000000;
		for(int i=0;i<=1000;i++)
		{
			if(p[i].flag==1&&p[i].x<0)
			{
				if(p[i].id==n-1)
				{
					minx=min(minx,0);
				}
				else
					minx=min(minx,p[i].id+1);
			}
		}
		printf("%d\n",minx);
	}
	return 0;
}
