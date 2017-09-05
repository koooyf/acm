#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int k;
bool check(int x)
{
//	printf("x=%d k=%d\n",(1+x)*x/2,k);
	if(((1+x)*x)/2>k)
		return 1;
	else
		return 0;
}
int find(int L,int r)
{
	while(r-L>1)
	{
		int mid=(L+r)>>1;
		if(check(mid)) r=mid;
		else
			L=mid;
//		printf("L=%d r=%d\n",L,r);
	}
	int ans=check(L)?L:r;
	if(!check(r)) return -1;
	else
		return ans;
}
int main()
{
	int a[30]={0};
	scanf("%d",&k);
	int cnt=0;
	if(k==0)
	{
		printf("a\n");
		return 0;
	}
	while(k>0)
	{
		cnt++;
		int ans=find(1,1000);
//		printf("%d\n",ans);
		k-=ans*(ans-1)/2;
		a[cnt]=ans;
	}
	for(int i=1;i<=26;i++)
	{
		for(int j=1;j<=a[i];j++)
			printf("%c",i+96);
	}
	printf("\n");
	return 0;
}
