#include<cstdio>
#include<queue>
using namespace std;
const int qwq[][2]={1,0,0,1,-1,0,0,-1};
struct point{
	int x,y,time;
};
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		char map[205][205];
		for(int i=1;i<=n;i++) scanf("%s",map[i]+1);
		int time[205][205];
		for(int i=0;i<=n+1;i++){
			for(int j=0;j<=m+1;j++){
				time[i][j]=2147483647;
			}
		}
		point tmp;
		queue<point> tea;
		tmp.time=0;
		for(int i=0;i<=n+1;i++){
			time[i][0]=0;
			tmp.x=i;
			tmp.y=0;
			tea.push(tmp);
			time[i][m+1]=0;
			tmp.y=m+1;
			tea.push(tmp);
		}
		for(int j=0;j<=m+1;j++){
			time[0][j]=0;
			tmp.x=0;
			tmp.y=j;
			tea.push(tmp);
			time[n+1][j]=0;
			tmp.x=n+1;
			tea.push(tmp);
		}
		while(!tea.empty()){
			point top=tea.front();
			tea.pop();
			for(int k=0;k<4;k++){
				int tx=top.x+qwq[k][0],ty=top.y+qwq[k][1],tt=top.time+1;
				if(tx<1||ty<1||tx>n||ty>m) continue;
				if(map[tx][ty]=='.') tt--;
				if(time[tx][ty]<=tt) continue;
				time[tx][ty]=tt;
				tmp.x=tx;
				tmp.y=ty;
				tmp.time=tt;
				tea.push(tmp);
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d ",time[i][j]);
			}
			printf("\n");
		}*/
		int sx,sy,ex,ey;
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		queue<point> team;
		tmp.x=sx;
		tmp.y=sy;
		tmp.time=0;
		team.push(tmp);
		bool flag=false,f[205][205]={false};
		while(!team.empty()){
			point top=team.front();
			team.pop();
			if(top.x==ex&&top.y==ey){
				printf("Tank can be transferred out of the island at second %d! ( ^_^ )\n",top.time);
				flag=true;
				break;
			}
			for(int k=0;k<4;k++){
				int tx=top.x+qwq[k][0],ty=top.y+qwq[k][1],tt=top.time+1;
				if(tx<1||ty<1||tx>n||ty>m) continue;
				if(tt>=time[tx][ty]||map[tx][ty]=='.') continue;
				if(f[tx][ty]) continue;
				f[tx][ty]=true;
				tmp.x=tx;
				tmp.y=ty;
				tmp.time=tt;
				team.push(tmp);
			}
		}
		if(!flag) printf("Oh, no! Tank will be drowned! QwQ\n");
	}
	return 0;
}
