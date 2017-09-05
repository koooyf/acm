#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char s[10],a[10]="Dang";
	scanf("%s",s);
	if(s[0]<'1'||(s[0]=='1'&&s[2]<'2'))
		printf("Only %s.  Too early to Dang.\n",s);
	else
	{
		int sum=0;
		sum=10*(s[0]-'0');
		sum+=(s[1]-'0')-12;
		if(s[3]==0&&s[4]==0)
		{
			for(int i=1;i<=sum;i++)
				printf("%s",a);
			printf("\n");
		}
		else
		{
			for(int i=1;i<=sum+1;i++)
				printf("%s",a);
			printf("\n");
		}
	}
	return 0;
}
