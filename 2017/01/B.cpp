#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct point{
	int x;
	int y;
}p[10];
bool cmp(point a,point b)
{
	if(a.x<b.x)
		return 1;
	if(a.x==b.x&&a.y>b.y)
		return 1;
	return 0;
}
int f(point a,point b,point c)
{
	point d;
	 d.x=b.x-a.x;
	 d.y=b.y-a.y;
	return c.x*d.y-c.y*d.x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int cnt=0;
		int ans=0;
		for(int i=1;i<=3;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		sort(p+1,p+4,cmp);
		scanf("%d%d",&p[4].x,&p[4].y);
		for(int i=5;i<=7;i++)
			scanf("%d%d",p[i].x,p[i].y);
		scanf("%d%d",&p[8].x,&p[8].y);
		p[9].x=p[5].x-p[3].x,p[9]=p[5].y-p[3].y;
		p[10].x=p[4].x-p[5].x,p[10].y=p[4].y-p[5].y;
		p[11].x=p[3].x-p[4].x,p[11].y=p[3].y-p[4].y;
		for(int i=5;i<=7;i++)
		{
			int c1=f(p[1],p[i],p[9]);
			int c2=f(p[3],p[i],p[10]);
			int c3=f(p[])
		}

	}
	return 0;
}
