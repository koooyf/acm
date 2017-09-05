#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char s[300000];
int f[300000];
int main()
{
	int n,a,b,k;
	scanf("%d%d%d%d",&n,&a,&b,&k);
	scanf("%s",s);
	memset(f,0,sizeof(f));
	int len=a*b;
	int ans=0,sum=0,tot=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			ans++;
			if(ans==b)
			{
				sum++;
				ans=0;
			}
		}
		else if(s[i]=='1')
			ans=0;
	}
	ans=0;
	for(int i=0;i<n;i++)
	{
		if(sum-tot<a)
			break;
		if(s[i]=='0')
		{
			ans++;
			if(ans==b)
			{
				tot++;
				f[tot]=i+1;
				ans=0;
			}
		}
		else if(s[i]=='1')
			ans=0;
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot-1;i++)
		printf("%d ",f[i]);
	printf("%d\n",f[tot]);
	return 0;
}
