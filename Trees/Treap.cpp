#include<cstdio>
#include<cstdlib>
#include<cstring>
const int MAXN=100000;
struct node{
	int left,right,val,fix;
};
struct treap{
	int root,size;
	node a[MAXN];
};
treap q;
void left_rotate(int x){
	node b=q.a[q.a[x].right];
	q.a[x].right=b.left;
	b.left=x;
	q.a[x]=b;
}
void right_rotate(int x){
	node b=q.a[q.a[x].left];
	q.a[x].left=b.right;
	b.right=x;
	q.a[x]=b;
}
void insert(int x,int val,int last,int dir){
	if(x==0){
		q.size++;
		x=q.size;
		q.a[x].val=val;
		q.a[x].fix=rand();
		if(q.root==0) q.root=x;
		if(last>0){
			printf("%d %d %d\n",x,last,dir);
			if(dir==0) q.a[last].left=x; else q.a[last].right=x;
		}
		return;
	}
	if(val<=q.a[x].val){
		insert(q.a[x].left,val,x,0);
		if(q.a[q.a[x].left].fix<q.a[x].fix) right_rotate(x);
	}else{
		insert(q.a[x].right,val,x,1);
		if(q.a[q.a[x].right].fix<q.a[x].fix) left_rotate(x);
	}
}
void del(int x,int val){
}
int find(int x,int val){
	if(x>q.size) return false;
	if(q.a[x].val==val) return x;
	if(val<q.a[x].val) return find(q.a[x].left,val);
	find(q.a[x].right,val);
}
void init(){
	q.size=0;
	q.root=0;
	memset(q.a,0,sizeof(q.a));
}
void print(int x){
	if(x>q.size) return;
	print(q.a[x].left);
	printf("%d\n",q.a[x].val);
	print(q.a[x].right);
}
int main(){
	init();
	int a;
	while(scanf("%d",&a)!=EOF){
		if(a==1){
			int b;
			scanf("%d",&b);
			insert(q.root,b,0,0);
		}else if(a==2){
			int b;
			scanf("%d",&b);
			del(q.root,b);
		}else if(a==3){
			int b;
			scanf("%d",&b);
			printf("%d\n",find(q.root,b));
		}
		printf("%d %d\n",q.a[q.root].left,q.a[q.root].right);
	}
	return 0;
}
