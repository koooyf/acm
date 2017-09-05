#include<cstdio>
const int MAXN = 100000;
struct heap{
	int val[MAXN], size;
};
heap a;
int swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int push(int x){
	a.size++;
	a.val[a.size] = x;
	int i = a.size;
	while(i > 1 && a.val[i] < a.val[i / 2]){
		swap(a.val[i], a.val[i / 2]);
		i /= 2;
	}
}
void min_heapify(int i){
	int minn = i;
	if(i * 2 <= a.size && a.val[i * 2] < a.val[minn]) minn = i * 2;
	if(i * 2 + 1 <= a.size && a.val[i * 2 + 1] < a.val[minn]) minn = i * 2 + 1;
	if(minn != i){
		swap(a.val[i], a.val[minn]);
		min_heapify(minn);
	}
}
int pop(){
	a.val[1] = a.val[a.size];
	a.size--;
	min_heapify(1);
}
void build(int n){
	a.size = n;
	for(int i = n / 2; i > 0; i--) min_heapify(i);
}
void init(){
	a.size = 0;
}
int main(){
	init();
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) scanf("%d", &a.val[i]);
	build(n);
	int x,y;
	while(scanf("%d",&x)!=EOF){
		if(x==1){
			scanf("%d",&y);
			push(y);
		}else{
			pop();
		}
			printf("%d\n",a.val[1]);
	}
	return 0;
}
