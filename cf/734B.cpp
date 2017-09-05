#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int k2,k3,k5,k6;
	long long sum=0;
	scanf("%d%d%d%d",&k2,&k3,&k5,&k6);
	int mn=100000000;
	mn=min(mn,k2);
	mn=min(mn,k5);
	mn=min(mn,k6);
	sum+=mn*256;
	k2-=mn;
	mn=100000000;
	mn=min(mn,k2);
	mn=min(mn,k3);
	printf("%I64d\n",sum+32*mn);
	return 0;
}
