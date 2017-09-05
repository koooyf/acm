#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
struct point{
	double  x;
	double y;
	int id;
}p[10];
const double esp=1e-8;
bool cmp(point a,point b)
{
	if(a.x*b.y-a.y*b.x<0)
		return 1;
	return 0;
}

int main()
{
	for(int i=1;i<=3;i++)
	{
		scanf("%lf%lf",&p[i].x,&p[i].y);
		p[i].id=i;
	}
	long double x=(p[3].x+p[1].x)/2.0;
	long double y=(p[3].y+p[1].y)/2.0;
	long double xx=p[3].x-p[1].x;
	long double yy=p[3].y-p[1].y;
	long double xxx=p[2].x-x;
	long double yyy=p[2].y-y;
	if(xxx==0&&yyy==0)
	{
		printf("No\n");
		return 0;
	}
	if(abs(xx*xxx+yy*yyy)<=esp)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
