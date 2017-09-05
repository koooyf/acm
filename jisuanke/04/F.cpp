#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct point{
	int w;
	int v;
}p[200];
bool cmp(point a, point b)
{
	if(a.w<b.w)
		return 1;
	else if(a.w==b.w&&a.v<b.v)
		return 1;
	return 0;
}
int main()
{
	int n,ww,vv;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&ww,&vv);
			p[i].w=ww,p[i].v=vv;
		}
//		sort(p+1,p+n+1,cmp);
		bool f=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(p[i].w<p[j].w&&p[i].v>p[j].v)
					f=1;
			}
		}
		if(f)
			printf("A company will go bankruptcy!\n");
		else
			printf("No company will go bankruptcy!\n");
	}
	return 0;
}
