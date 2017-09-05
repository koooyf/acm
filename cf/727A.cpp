#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long a,b;
int c[1000]={0};
bool f=0;
int m;
void dfs(long long sum,int k)
{
	if(sum>b||f==1)
		return ;
	if(sum==b)
	{
		f=1;		
		printf("YES\n%d\n",k+1);
		m=k+1;
		c[k+1]=b;
		return ;
	}
	dfs(2*sum,k+1);
	dfs(10*sum+1,k+1);
	c[k+1]=sum;
}
int main()
{
	while(scanf("%I64d%I64d",&a,&b)!=EOF)
	{
		dfs(a,0);
		if(f==0)
			printf("NO\n");
		if(f==1)
		{
			printf("%d",c[1]);
			for(int i=2;i<=m;i++)
				printf(" %d",c[i]);
			printf("\n");
		}	
	}
	return 0;
}
