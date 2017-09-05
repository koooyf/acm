#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int main()
{
	int n,x,a[6][3]={0,1,2,1,0,2,1,2,0,2,1,0,2,0,1,0,2,1};
	scanf("%d",&n);
	scanf("%d",&x);
	
	printf("%d\n",a[n%6][x]);
	return 0;
}
