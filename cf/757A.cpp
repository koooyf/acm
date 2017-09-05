#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char a[200000],s[16]="Bulbasaur";
int c[2500];
int main()
{
	while(scanf("%s",a)!=EOF)
	{
		memset(c,0,sizeof(c));
		int t=strlen(a);
		for(int i=0;i<t;i++)
		{
			c[a[i]-'0']++;
		}
		int minx=10000000;
		for(int i=0;i<9;i++)
		{
			if(s[i]=='b')
			minx=min(minx,c[s[i]-'0']);
			else if(s[i]=='u')
			minx=min(minx,c[s[i]-'0']/2);
			else if(s[i]=='a')
			minx=min(minx,c[s[i]-'0']/2);
			else 
			minx=min(minx,c[s[i]-'0']);	
		}
		printf("%d\n",minx);
	}
	return 0;
}
