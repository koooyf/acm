#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char a[200],s[4];
	int d[4];
	scanf("%s",a);
	int t=strlen(a);
	memset(d,0,sizeof(d));
	for(int i=0;i<t;i++)
	{
		if(a[i]=='!')
			continue;
		s[i%4]=a[i];
	}
	for(int i=0;i<=t;i++)
	{
		if(a[i]=='!')
		{
			if(s[i%4]=='R')
				d[0]++;
			else if(s[i%4]=='B')
				d[1]++;
			else if(s[i%4]=='Y')
				d[2]++;
			else if(s[i%4]=='G')
				d[3]++;
		}
	}
	printf("%d %d %d %d\n",d[0],d[1],d[2],d[3]);
	return 0;
}
