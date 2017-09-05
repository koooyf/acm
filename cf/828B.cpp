#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n,m,x=200,y=200,xx=-1,yy=-1,sum=0;
	char mp[200][200];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",mp[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]=='B')
			{
				if(i<x)
					x=i;
				if(j<y)
					y=j;
				if(i>xx)
					xx=i;
				if(j>yy)
					yy=j;
				sum++;	
			}
		}
	}
	int maxx=max(xx-x+1,yy-y+1);
	if(sum>0)
	{
	if(maxx>n||maxx>m)
		printf("-1\n");
	else printf("%d\n",maxx*maxx-sum);
	}
	else
		printf("1\n");
	return 0;
}
