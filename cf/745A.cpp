#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char a[100],b[100],d[100];
	scanf("%s",a);
	int t=strlen(a);
	strcpy(b,a);
	strcpy(d,a);
	int num=1;
	char c;
	c=d[t-1];
	for(int i=0;i<t-1;i++)
	{
		b[i+1]=d[i];	
	}
	b[0]=c;
	while(strcmp(a,b)!=0)
	{
		strcpy(d,b);
		c=d[t-1];
		for(int i=0;i<t-1;i++)
		{
			b[i+1]=d[i];
		}
		b[0]=c;
		num++;
	//	printf("%s\n",a);
	//	printf("%s\n",b);
	}
	printf("%d\n",num);
	return 0;
}
