#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
int n,m;
bool f=0;
int mp[200][200],st,se,vt,ve,dis[4][2]={-1,0,1,0,0,1,0,-1},vis[200][200];
struct point{
	int i;
	int j;
	int step;
};
void bfs()
{
	queue<point>q;
	point now;
	memset(vis,0,sizeof(vis));
	now.i=st,now.j=se,now.step=0;
	vis[st][se]=1;
	q.push(now);
	while(!q.empty())
	{
		point now=q.front();
		q.pop();
		point nt;
		if(now.i==vt&&now.j==ve)
		{
			f=1;
			printf("%d\n",now.step);
			break;
		}
		for(int i=0;i<4;i++)
		{
			int xx=now.i+dis[i][0];
			int yy=now.j+dis[i][1];
			if(vis[xx][yy]||xx<1||xx>n||yy<1||yy>m||mp[xx][yy]==1)
				continue;
			nt.i=xx,nt.j=yy,nt.step=now.step+1;
			q.push(nt);
			vis[xx][yy]=1;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&mp[i][j]);
			if(mp[i][j]==2)
				st=i,se=j;
			else if(mp[i][j]==3)
				vt=i,ve=j;
		}
	bfs();
	if(!f)
		printf("-1\n");
	return 0;
}
