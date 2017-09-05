#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,a[1050];
bool solve(double k)
{
	bool f=0;
	int where=-1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[1]==k*(i-1))
			continue;
		f=1;
		if(where==-1) where=i;
		else if(a[i]-a[where]!=k*(i-where))
		{
			f=0;
			break;
		}
	}
	if(f) return 1;
	else
		return 0;
}
int main()
{	
	scanf("%d",&n);
	double k1,k2,k3;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	k1=(double)(a[2]-a[1]);
	k2=(double)(a[3]-a[1])*0.5;
	k3=(double)(a[3]-a[2]);
	bool flag=0;
	if(solve(k1)||solve(k2)||solve(k3)) flag=1;
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
