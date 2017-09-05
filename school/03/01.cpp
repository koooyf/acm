#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int sum,t,c;
	while(scanf("%d",&t)!=EOF)
	{
		sum=0;
		for(int i=1;i<=t;i++)
		{
			scanf("%d",&c);
			if(c<=35)
				sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
