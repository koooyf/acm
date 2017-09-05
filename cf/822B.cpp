#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,m,maxn=0,f[1050];
	char s[1050],t[1050];
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	memset(f,0,sizeof(f));
	scanf("%s",t);
	for(int i=0;i<=m-n;i++)
	{
		int sum=0;
		for(int j=0;j<n;j++)
		{
			if(s[j]==t[i+j])
				sum++;
		}
		if(sum>=maxn)
		{
			maxn=sum;
			int tot=0;
			for(int j=0;j<n;j++)
			{
				if(s[j]!=t[i+j])
				{
					tot++;
					f[tot]=j+1;
//					printf("%d\n",f[tot]);
				}
			}
		}	
	}
	printf("%d\n",n-maxn);
	if(n-maxn>0)
	{
	for(int i=1;i<n-maxn;i++)
		printf("%d ",f[i]);
	printf("%d\n",f[n-maxn]);
	}
	return 0;
}
