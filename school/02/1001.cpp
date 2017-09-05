#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 90000
int main()
{
	char a[N],b[N];
	int n,x,y,t;
	scanf("%d",&t);
	while(t--)
	{
		int sum=0;
		bool flag=0;
		scanf("%d%d%d",&n,&x,&y);
		scanf("%s",a);
		scanf("%s",b);
		for(int i=0;i<n;i++)
			if(a[i]==b[i])
				sum++;
		for(int i=0;i<=sum&&i<=x;i++)
		{
			int p=x-i;
			if(n-sum<p)
				continue;
			int yy=i+(n-sum-p);
			if(y>=i&&y<=yy)
				flag=1;
		}
		if(flag==1)
			printf("Not lying\n");
		else
			printf("Lying\n");
	}
	return 0;
}
