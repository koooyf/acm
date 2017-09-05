#include<cstdio>
const int MAXN=100000;
struct queue{
	int val[MAXN], head, tail, len;
};
queue a;
void push(int v){
	a.tail = (a.tail + 1) % MAXN;
	a.val[a.tail] = v;
	a.len++;
}
void pop(){
	a.head = (a.head + 1) % MAXN;
	a.len--;
}
void init(){
	a.tail = -1;
	a.head = 0;
}
void print(){
	if(a.len == 0) return;
	for(int i = a.head; i != a.tail; i = (i + 1) % MAXN) printf("%d\n", a.val[i]);
	printf("%d\n", a.val[a.tail]);
}
int main(){
	init();
	int a, b;
	while(scanf("%d", &a) != EOF){
		if(a == 1){
			scanf("%d", &b);
			push(b);
		}else{
			pop();
		}
		print();
	}
	return 0;
}
