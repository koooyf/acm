#include<cstdio>
const int MAXN=100000;
int st[MAXN*4],mark[MAXN*4],a[MAXN];
int max(int a,int b){
	if(a>b) return a;
	return b;
}
void push_up(int x){
	st[x]=max(st[x<<1],st[x<<1|1]);
}
void push_down(int x){
	st[x<<1]+=mark[x];
	mark[x<<1]+=mark[x];
	st[x<<1|1]+=mark[x];
	mark[x<<1|1]+=mark[x];
	mark[x]=0;
}
void build(int x,int l,int r){
	if(l==r){
		st[x]+=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(x<<1,l,m);
	build(x<<1|1,m+1,r);
	push_up(x);
}
void update(int point,int val,int x,int l,int r){
	if(l==r){
		st[x]=val;
		return;
	}
	int m=(l+r)>>1;
	if(point<=m) update(point,val,x<<1,l,m); else update(point,val,x<<1|1,m+1,r);
	push_up(x);
}
void update_seg(int left,int right,int val,int x,int l,int r){
	if(left<=l&&r<=right){
		st[x]=val*(r-l+1);
		mark[x]=val;
		return;
	}
	if(mark[x]) push_down(x);
	int m=(l+r)>>1;
	if(left<=m) update_seg(left,right,val,r<<1,l,m);
	if(right>m) update_seg(left,right,val,r<<1|1,m+1,r);
	push_up(x);
}
int query(int left,int right,int x,int l,int r){
	if(left<=l&&r<=right) return st[x];
	if(mark[x]) push_down(x);
	int m=(l+r)>>1,ans=0;
	if(left<=m) ans=max(ans,query(left,right,x<<1,l,m));
	if(right>m) ans=max(ans,query(left,right,x<<1|1,m+1,r));
	return ans;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	int a;
	while(scanf("%d",&a)!=EOF){
		if(a==1){
			int b,c;
			scanf("%d%d",&b,&c);
			update(b,c,1,1,n);
		}else if(a==2){
			int b,c,d;
			scanf("%d%d%d",&b,&c,&d);
			update_seg(b,c,d,1,1,n);
		}else{
			int b,c;
			scanf("%d%d",&b,&c);
			printf("%d\n",query(b,c,1,1,n));
		}
		for(int i=1;i<=n;i++) printf("%d ",query(i,i,1,1,n));
		printf("\n");
	}
	return 0;
}
