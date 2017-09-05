#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int t,mp[7][7];
struct point{
	int x;
	int y;
	int i;
	int j;
	int v;
	int step;
};
int dis[4][2]={-1,0,-1,-1,1,0,1,1};
int ans=0;
queue<point>q;
void bfs()
{
	while(!q.empty())
	{
		point now=q.front();
		q.pop();
		if(now.i==now.v)
			ans--;
		else
			ans++;
		if(ans==0)
		{
			printf("%d\n",now.step);
		}
		for(int i=0;i<4;i++)
		{
			int xx=now.i+dis[i][0];
			int yy=now.j+dis[i][1];
			q.push((point){now.x,now.y,xx,yy,now.v,now.step+1});
			q.push((point){xx,yy,now.i,now.j,mp[xx][yy],now.step+1});
		}
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<6;i++)
			for(int j=0;j<=i;j++)
			{
				scanf("%d",&mp[i][j]);
				if(mp[i][j]!=i)
				{
					ans++;
				}
			}
	//	q.clear();
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<=i;j++)
			{
				if(mp[i][j]!=i)
				{
					q.push((point){i,j,i,j,mp[i][j],0});
					break;
				}
			}
		}
		bfs();
	}
	return 0;
}
