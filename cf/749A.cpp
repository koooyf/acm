#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int f[100005],id=0;
void search()
{
	for(int i=2;i<=100005;i++)
	{
		int t=sqrt(i);
		bool flag=0;
		for(int j=2;j<=t;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;		
			}
		}
		if(!flag)
		{
			id++;
			f[id]=i;
		}
	}	
}
int main()
{
	int n,m,ans[100005],cnt=0;
	scanf("%d",&n);
	search();
		for(int i=1;i<=id;i++)
		{
			if(n==0) break;
			while(n-f[i]>1||n-f[i]==0)
			{
				cnt++;
				ans[cnt]=f[i];
				n=n-f[i];		
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<cnt;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans[cnt]);
	return 0;
}
