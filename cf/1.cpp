#include<cstdio>
  const int N=100010;
  int n,i,x,y,g[N],v[N<<1],nxt[N<<1],ed;
  double f[N];
  void add(int x,int y){v[++ed]=y;nxt[ed]=g[x];g[x]=ed;}
  void dfs(int x,int y){
    int deg=0;
    for(int i=g[x];i;i=nxt[i])if(v[i]!=y){
      deg++;
      dfs(v[i],x);
     f[x]+=f[v[i]];
   }
   if(deg)f[x]=1.0*f[x]/deg+1;
 }
 int main(){
   scanf("%d",&n);
   for(i=1;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
   dfs(1,0);
   printf("%.10f",f[1]);
 }
