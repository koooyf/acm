#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
int n,s;
double cost[505],mp[505][505];
struct point{
	double x;
	double y;
}p[505];
int vis[505];
vector<int>q;
double prim()
{
	double ans=0;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	for(int i=1;i<=n;i++)
		cost[i]=mp[1][i];
	for(int i=2;i<=n;i++)
	{
		int id;
		double maxx=1000000000;
		for(int j=1;j<=n;j++)
		{
			if(maxx>cost[j]&&!vis[j])
			{
				maxx=cost[j];
				id=j;
			}
		}
		vis[id]=1;
		if(ans<maxx)
			ans=maxx;
		for(int j=1;j<=n;j++)
		{
			if(cost[j]>mp[id][j])
				cost[j]=mp[id][j];
		}
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&s,&n);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		int x,y;
		double minn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				double sum=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
				mp[i][j]=sum;
				mp[j][i]=sum;
				if(sum>minn)
				{
					minn=sum;
					x=i,y=j;
				}
			}
		}
		q.clear();
		if(s>=2)
		{
			mp[x][y]=0;
			mp[y][x]=0;
			memset(vis,0,sizeof(vis));
			vis[x]=1,vis[y]=1;
			q.push_back(x);
			q.push_back(y);
			s-=2;
		for(int k=1;k<=s;k++)
		{
			int id;
			double maxx=0;
			for(int i=1;i<=n;i++)
			{
				double sum=0;
				for(int j=0;j<q.size();j++)
				{
						sum+=mp[i][q[j]];
				}
				if(maxx<sum&&!vis[i])
				{
					maxx=sum;
					id=i;
				}
			}
			for(int i=0;i<q.size();i++)
			{
				mp[q[i]][id]=0;
				mp[id][q[i]]=0;
			}
			q.push_back(id);
			vis[id]=1;
		}
		}
		printf("%.2f\n",prim());
	}
	return 0;
}
