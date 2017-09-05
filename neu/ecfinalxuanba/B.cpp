#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[100005];
char num[100005][30]={0};
int main(){
	f[1]=1;
	num[1][1]='1';
	for(int i=2;i<=30;i++){
		f[i]=f[i-1]*2;
		int cnt=-1,t=f[i];
		while(t>0){
			cnt++;
			num[i][cnt]='0'+t%10;
			t/=10;
		}
		sort(num[i],num[i]+strlen(num[i]));
		f[i]=0;
		for(int j=0;j<strlen(num[i]);j++){
			f[i]=f[i]*10-'0'+num[i][j];
		}
	}
	int t;
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++){
		int n;
		scanf("%d",&n);
		printf("Case #%d: ",ca);
		if(n<=30) printf("%d\n",f[n]);
		else{
			n=(n-25)%6+25;
			printf("%d\n",f[n]);
		}
	}
	return 0;
}
