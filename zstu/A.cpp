#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		int sum=k-1-1;
		int ans=n-(k+1);
		if((ans+sum)%2==1)
			printf("LYF\n");
		else
			printf("BH\n");
	}
	return 0;
}
