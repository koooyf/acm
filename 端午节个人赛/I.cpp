#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	char n[100000];
	while(scanf("%s",n)!=EOF)
	{
		int t=strlen(n);
		long long sum=0;
		for(int i=0;i<t;i++)
		{
			sum+=n[i]-'0';
		}
		if(sum%3==0)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}
