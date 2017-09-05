#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char a[150],b[150];
	while(scanf("%s",b)!=EOF)
	{
		int t=strlen(b);
		b[t]='A';
		b[t+1]='\n';
		int mx=0;
		int where=0,middle=0;
		for(int i=1;i<=t+1;i++)
			a[i]=b[i-1];
			a[0]='g';
		for(int i=0;i<=t+1;i++)
		{
			if(a[i]=='O'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='U'||a[i]=='Y')
			{
				middle=i-where;
				where=i;
				mx=max(mx,middle);
//				printf("%d %d %d\n",mx,where,i);
			}
		}
		printf("%d\n",mx);
	}
	return 0;
}
