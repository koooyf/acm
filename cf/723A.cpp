#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int a[3];
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	int mn=1000000000;
	int t=a[0];
	while(t++&&t<=a[2])
	{
		int x=abs(t-a[0]);
		int y=abs(t-a[1]);
		int z=abs(t-a[2]);
		mn=min(mn,x+y+z);
	}
	printf("%d\n",mn);
	return 0;
}
