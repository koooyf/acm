#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct point{
	int v;
	int w;
}p[1000000];
bool cmp(point x,point y)
{
	return x.v>y.v;
}
int n,a[1000000],b[1000000],c[1000000];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		p[i]=(point){b[i],i};
	sort(p+1,p+n+1,cmp);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		c[p[i].w]=a[i];
	}
	printf("%d",c[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",c[i]);
	printf("\n");
	return 0;
}
