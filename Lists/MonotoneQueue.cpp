#include<cstdio>
const int MAXN = 100000;
struct monoqueue{
	int val[MAXN], id[MAXN], head, tail;
};
int lim;
monoqueue a;
void print(){
	for(int i = a.head; i <= a.tail; i++) printf("%d\n", a.val[i]);
}
void push(int v, int x){
	while(a.tail >= a.head && a.val[a.tail] > v) a.tail--;
	a.tail++;
	a.val[a.tail] = v;
	a.id[a.tail] = x;
	while(a.id[a.tail] - a.id[a.head] + 1 > lim) a.head++;
}
void init(){
	a.head = 0;
	a.tail = -1;
}
int main(){
	init();
	int a, i = 0;
	scanf("%d", &lim);
	while(scanf("%d", &a)!=EOF){
		push(a, i);
		i++;
		print();
	}
	return 0;
}
