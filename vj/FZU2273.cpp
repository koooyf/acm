#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct point{
	int x;
	int y;
}p[20];
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
		scanf("%d%d",&p[10].x,&p[10].y);
		for(int i=4;i<=6;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		scanf("%d%d",&p[11].x,&p[11].y);
		sort(p+1,p+4,cmp);
		p[7].x=p[3].x-p[1].x,p[7].y=p[3].y-p[1].y;
		p[8].x=p[2].x-p[3].x,p[8].y=p[2].y-p[3].y;
		p[9].x=p[1].x-p[2].x,p[9].y=p[1].y-p[2].y;
		if(p[2].y>=min(p[1].y,p[3].y))
		{
			for(int i=4;i<=6;i++)
			{
				int c1=f(p[1],p[i],p[7]);
				int c2=f(p[3],p[i],p[8]);
				int c3=f(p[2],p[i],p[9]);
				if(c1>0&&c2>0&&c3>0)
					cnt++;
				else if(c1<0||c2<0||c3<0)
					ans++;
			}
			 if(cnt==3)
			{
				if(p[10].x*p[11].y==p[10].y*p[11].x)
					printf("NO\n");
				else if((p[10].y>0&&p[11].y<0)||(p[10].y<0&&p[11].y>0))
					printf("NO\n");
				else
					printf("YES\n");
			}
			else
				printf("YES\n");
		}
		else
		{
			for(int i=4;i<=6;i++)
			{
				int c1=f(p[1],p[i],p[7]);
				int c2=f(p[3],p[i],p[8]);
				int c3=f(p[2],p[i],p[9]);
				if(c1<0&&c2<0&&c3<0)
					cnt++;
				else if(c1>0||c2>0||c3>0)
				{
					ans++;
				}
			}
			 if(cnt==3)
			{
				if(p[10].x*p[11].y==p[10].y*p[11].x)
					printf("NO\n");
				else if((p[10].y>0&&p[11].y<0)||(p[10].y<0&&p[11].y>0))
					printf("NO\n");
				else
					printf("YES\n");
			}
			else
				printf("YES\n");
		}
	}
	return 0;
}
