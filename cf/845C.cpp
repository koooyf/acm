#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
struct point{
	int x;
	int v;
}p[400005];
bool cmp(point a,point b)
{
	if(a.x<b.x)
	return 1;
	else if(a.x==b.x&&a.v>b.v)
		return 1;
	return 0;
}
int main()
{
	int n;
	int a,b;
	scanf("%d",&n);
	int j=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		j++;
		p[j].x=a;
		p[j].v=1;
		j++;
		p[j].x=b;
		p[j].v=-1;
	}
	sort(p+1,p+2*n+1,cmp);
	bool flag=0;
	for(int i=1;i<=2*n;i++)
	{	
		ans+=p[i].v;
		if(ans>=3)
			flag=1;
//		printf("%d\n",ans);
	}
	if(flag)
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}
