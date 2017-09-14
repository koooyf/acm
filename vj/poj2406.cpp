#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int nx[1000050],ans=0;
char p[1000050];
void getnext()
{
	int k=-1,j=0;
	nx[0]=-1;
	int pLen=strlen(p);
	while(j<pLen)
	{
		if(k==-1||p[k]==p[j])
		{
			j++;
			k++;
			nx[j]=k;
		}
		else
			k=nx[k];
	}
}
int main()
{
	while(true)
	{
		gets(p);
		if(strcmp(p,".")==0)
			break;
		if(strcmp(p,"")==0)
		{
			printf("0\n");
			continue;
		}
		getnext();
		int len=strlen(p);
			int lenth=len-nx[len];
			if(!(len%lenth))
				printf("%d\n",len/lenth);
			else
				printf("1\n");
	}
	return 0;
}
