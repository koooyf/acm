#include<cstdio>
const int MAXN=100000;
int a[MAXN],bit[MAXN];
int n;
int lowbit(int x){
	return x&-x;
}
void add(int x,int v){
	for(int i=x;i<=n;i+=lowbit(i)) bit[i]+=v;
}
int sum(int x){
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i)) ans+=bit[i];
	return ans;
}
void build(){
	for(int i=1;i<=n;i++){
		bit[i]=a[i];
		for(int j=i-1;j>i-lowbit(i);j--) bit[i]+=a[j];
	}
}
void print(){
	for(int i=1;i<=n;i++) printf("%d ",sum(i)-sum(i-1));
	printf("\n");
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build();
	int a,b,c;
	while(scanf("%d",&a)!=EOF){
		if(a==1){
			scanf("%d%d",&b,&c);
			add(b,c);
		}else{
			scanf("%d",&b);
			printf("%d\n",sum(b));
		}
		print();
	}
	return 0;
}
