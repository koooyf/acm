#include<cstdio>
const int MAXN = 100000;
struct node{
	int val, pre, suf;
};
node list[MAXN];
void insert(int a, int b){
	list[a].suf = list[b].suf;
	list[a].pre = b;
	list[list[b].suf].pre = a;
	list[b].suf = a;
}
void del(int a){
	list[list[a].pre].suf = list[a].suf;
	list[list[a].suf].pre = list[a].pre;
	list[a].pre = -1;
	list[a].suf = -1;
}
void init(){
	for(int i = 0; i < MAXN; i++){
		list[i].pre = -1;
		list[i].suf = -1;
	}
}
void print(int a){
	while(a != -1){
		printf("%d %d\n", a, list[a].val);
		a = list[a].suf;
	}
}
int main(){
	init();
	int a, b, c;
	while(scanf("%d", &a) != EOF){
		if(a == 1){
			scanf("%d%d", &b, &c);
			list[b].val = c;
		}else if(a == 2){
			scanf("%d%d", &b, &c);
			insert(b, c);
		}else{
			scanf("%d", &b);
			del(b);
		}
		print(1);
	}
    return 0;
}
