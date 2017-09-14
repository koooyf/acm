#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int cost[2005],n,mp[2005][2005];
char s[2005][10];
bool vis[2005];
int prim()
{
	int ans=0;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	for(int i=1;i<=n;i++)
		cost[i]=mp[1][i];
	for(int i=2;i<=n;i++)
	{
		int maxx=1000000000;
		int id;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&maxx>cost[j])
			{
				maxx=cost[j];
				id=j;
			}
		}
		vis[id]=1;
		ans+=maxx;
	//	printf("%d\n",maxx);
		for(int j=1;j<=n;j++)
			if(cost[j]>mp[id][j])
				cost[j]=mp[id][j];
	}
	return ans;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int sum=0;
				for(int k=0;k<7;k++)
					if(s[i][k]!=s[j][k])
						sum++;
				mp[i][j]=sum;
				mp[j][i]=sum;
			}
		}
		printf("The highest possible quality is 1/%d.\n",prim());
	}
	return 0;
}
