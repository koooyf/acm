#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char s[200],a[200];
	bool f[200];
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int ans=0;
	memset(f,0,sizeof(f));
	for(int i=0;i<n;i++)
	{
		if(i<n-2)
		{
			if(s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o')
			{
				s[i]='*';
				s[i+1]='*';
				s[i+2]='*';
			}
		}
		if(i>=1)
		{
			if(s[i]=='g'&&s[i+1]=='o'&&s[i-1]=='*')
			{
				f[i]=1;
				f[i+1]=1;
				s[i]='*';
				s[i+1]='*';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(f[i]==0)
			printf("%c",s[i]);
	}	
	printf("\n");
	return 0;
}
