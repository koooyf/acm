#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int t,n;
	char s[1000];
	bool f[1000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		n=strlen(s);
		memset(f,0,sizeof(f));
		for(int i=0;i<n;i++)
		{
			if(s[i]=='#'&&i!=0)
			{
				f[i-1]=1;
				f[i]=1;
			}
			else if(s[i]=='#'&&i==0)
			{
				f[i]=1;
			}
			if(s[i]=='@')
			{
				for(int j=0;j<=i;j++)
					f[j]=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(f[i]==0)
				printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
