#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
struct node{
	int x,y,step;
};
queue<node> q;
int n,m,dir[4][2]={1,0,-1,0,0,1,0,-1},maxx=-1,maxy=-1,minxx=1000,minyy=1000,maxstep=1;
int vis[550][550]={0};
char mp[550][550];
void bfs(int xx,int yy)
{
	node now;
	now.x=xx,now.y=yy;
	now.step=1;
	vis[xx][yy]=1;
	q.push(now);
	while(!q.empty())
	{
		node tmp=q.front();
		if(tmp.x>maxx) maxx=tmp.x;
		if(tmp.y>maxy) maxy=tmp.y;
		if(tmp.x<minxx) minxx=tmp.x;
		if(tmp.y<minyy) minyy=tmp.y;
		q.pop();
		for(int i=0;i<=3;i++)
		{
			int xxx=tmp.x+dir[i][0],yyy=tmp.y+dir[i][1];
			if(tmp.x+dir[i][0]>=0&&tmp.x<n&&tmp.y+dir[i][1]>=0&&tmp.y+dir[i][1]<m&&mp[xxx][yyy]=='X')
			{
				if(vis[tmp.x+dir[i][0]][tmp.y+dir[i][1]]==0)
				{
					node next;
					next.x=tmp.x+dir[i][0];
					next.y=tmp.y+dir[i][1];
					maxstep++;
					next.step=tmp.step+1;
					vis[next.x][next.y]=1;
					q.push(next);
				}		
			}		
		}	
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",mp[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]=='X')
			{
				bfs(i,j);
			}
		}
	}
	int sum=(maxx-minxx+1)*(maxy-minyy+1);
//	printf("%d %d\n",sum,maxstep);
	if(sum==maxstep)
	printf("YES\n");
	else 
	printf("NO\n");	
	return 0;
}
