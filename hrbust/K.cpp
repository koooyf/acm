#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int t;
	char a[1000],c;
	int sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		int n=strlen(a);
		for(int i=0;i<n;i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				for(int j=1;j<=a[i]-'0';j++)
					printf("%c",c);
			}
			else
			{
				printf("%c",a[i]);
				c=a[i];
			}
		}
		printf("\n");
	}
	return 0;
}
