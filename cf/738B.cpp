#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int mp[1050][1050];
int main()
{
	int n,m,tot[2000][3],ans[2000][3];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mp[i][j]);
	memset(ans,0,sizeof(ans));
	memset(tot,0,sizeof(tot));
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==1&&ans[i][1]==0)
			{
				ans[i][1]=j;
			}
			if(mp[i][j]==1&&ans[i][1]!=0)
			{
				ans[i][2]=j;
			}
			if(mp[i][j]==1&&tot[j][1]==0)
				tot[j][1]=i;
			if(mp[i][j]==1&&tot[j][1]!=0)
				tot[j][2]=i;
		}
	}
//	for(int i=1;i<=n;i++)
//		printf("%d %d\n",ans[i][1],ans[i][2]);
//	for(int j=1;j<=m;j++)
//		printf("%d %d\n",tot[j][1],tot[j][2]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==0&&j>=ans[i][1]&&j<=ans[i][2])
				sum=sum+2;
			else if(mp[i][j]==0&&ans[i][1]!=0)
				sum++;
			if(mp[i][j]==0&&i>=tot[j][1]&&i<=tot[j][2])
				sum+=2;
			else if(mp[i][j]==0&&tot[j][1]!=0)
				sum++;
		}
	}
	printf("%d\n",sum);
	return 0;
}
