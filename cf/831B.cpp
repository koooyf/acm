#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char s1[30],s2[30],s3[1005];
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);
	int t=strlen(s3);
	for(int i=0;i<t;i++)
	{
		if(s3[i]>='a'&&s3[i]<='z')
		{
			for(int j=0;j<26;j++)
			{
				if(s1[j]==s3[i])
				{
					printf("%c",s2[j]);
				}
			}
		}
		else if(s3[i]>='A'&&s3[i]<='Z')
		{
			int a='A'-'a';
			for(int j=0;j<26;j++)
			{
				if(s1[j]+a==s3[i])
					printf("%c",s2[j]+a);
			}
		}
		else
			printf("%c",s3[i]);
	}
	printf("\n");
	return 0;
}
