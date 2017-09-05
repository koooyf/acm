#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int f[3005]={0};
int main()
{
	f[0]=1;
	for(int i=1;i<=10;i++)
	{
		f[i]=i*f[i-1];	
	}
	int t,n;
	double sum=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		if(n>1)
		{
			for(int i=0;i<n;i++)
			{
				sum=sum+(double)f[n-1]/(double)(n-i)*(double)n;
			}
			printf("%.1f\n",sum);
		}
		else if(n==1)
			printf("1.0\n");
	}
	return 0;
}
