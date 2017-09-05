#include<cstdio>
typedef long long LL;
const LL MOD=1000000007;
const LL MAXA=1000005;
LL step[MAXA+5],p[MAXA+5],hahahaha[MAXA+5];
void exgcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	int tmp=x;
	x=y;
	y=tmp-(a/b)*y;
}
LL modReverse(LL a,LL M){
	LL x,y;
	exgcd(a,M,x,y);
	return (x%M+M)%M;
}
int main(){
	step[0]=1;
	step[1]=1;
	p[1]=1;
	for(int i=2;i<=MAXA;i++){
		step[i]=step[i-1]*i%MOD;
		p[i]=(MOD-MOD/i)*p[MOD%i]%MOD;
	}
	for(int i=0;i<=MAXA;i++)
		hahahaha[i]=modReverse(step[i],MOD);
	int t;
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++){
		LL a,b;
		scanf("%lld%lld",&a,&b);
		printf("Case #%d: ",ca);
		if(b==0){
			printf("List, are you kidding me?\n");
			continue;
		}
		LL ans=0;
		for(int x=1;x<=a+1;x++){
			LL anss=step[a]*step[a+b-x]%MOD;
			anss=anss*x%MOD;
			anss=anss*hahahaha[a-x+1]%MOD;
			ans=(ans+anss)%MOD;
		}
		ans=ans*b%MOD;
		printf("%lld\n",ans);
	}
	return 0;
}
