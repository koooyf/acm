#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
struct point{
	double x,y,z,r;
}p[200];
int n;
double jisuan(point a,point b)
{
	double ans=sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)+(b.z-a.z)*(b.z-a.z))-b.r-a.r;
	if(ans<0)
		return 0;
	else
		return ans;
}
int vis[200];
double prim()
{
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	double ans=0;
	for(int k=2;k<=n;k++)
	{
		double minn=1000000000;
		int id;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(vis[i]&&!vis[j]&&minn>jisuan(p[i],p[j]))
				{
					id=j;
					minn=jisuan(p[i],p[j]);
				}
			}
		}
		vis[id]=1;
		ans+=minn;
	}
	return ans;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
		{
			double x,y,z,r;
			scanf("%lf%lf%lf%lf",&x,&y,&z,&r);
			p[i]=(point){x,y,z,r};
		}
		double ans=prim();
		printf("%.3f\n",ans);
	}
	return 0;
}
