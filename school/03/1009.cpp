#include<cstdio>
#include<cstring>
#include
#include<iostream>
using namespace std;
int main()
{
	int m,d[100][100],ans[100][100];
	while(scanf("%d,&m")!=EOF)
	{
		int sum=0,n=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&d[i][j]);
				n+=d[i][j];
				sum+=(i+j);
				ans[j]++
			}
		n++;

	}
	return 0;
}
