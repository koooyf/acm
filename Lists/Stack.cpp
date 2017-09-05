#include<cstdio>
const int MAXN = 100000;
struct stack{
	int val[MAXN], top;
};
stack a;
void push(int v){
	a.top++;
	a.val[a.top] = v;
}
void pop(){
	a.top--;
}
void init(){
	a.top = -1;
}
void print(){
	if(a.top == -1) return;
	for(int i = a.top; i >= 0; i--) printf("%d\n", a.val[i]);
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
