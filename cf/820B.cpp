#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;
double ff(double a, double b)
{
	if(a>=b)
		return a-b;
	else
		return b-a;
}
int main()
{
	int n,minn=3;
	double t,a;
	scanf("%d%lf",&n,&a);
	t=(n-2)*180;
	t=t/n/(n-2);
	for(int i=3;i<=n;i++)
	{
		if(ff((i-2)*t,a)<ff((minn-2)*t,a))
		{
			minn=i;
		}
	}
	printf("%d 1 2\n",minn);
	return 0;
}
