#include<cstdio>
const int MAXN = 1000000;
int par[MAXN + 5];
void init(){
	for(int i = 1; i <= MAXN; i++) par[i] = i;
}
int find(int x){
	if(par[x] == x) return x;
	par[x] = find(par[x]);
	return par[x];
}
void uni(int x, int y){
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	par[fy] = fx;
}
bool family(int x,int y){
	return find(x) == find(y);
}
int main(){
	init();
	char c[10];
	while(scanf("%s",c)!=EOF){
		if(c[0]=='s') break;
		if(c[0]=='u'){
			int a,b;
			scanf("%d%d",&a,&b);
			uni(a,b);
		}else{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%d %d %d\n",find(a),find(b),family(a,b));
		}
	}
	return 0;
}
