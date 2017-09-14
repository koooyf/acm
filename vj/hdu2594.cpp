#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char p[100000],s[100000];
int nx[100000];
void getnext(char *p)
{
	int k=-1,j=0;
	nx[0]=-1;
	int pLen=strlen(p);
	int sLen=strlen(s);
	while(j<pLen)
	{
		if(k==-1||p[k]==p[j])
		{
			j++;
			k++;
          //if(p[k]!=p[j])
			nx[j]=k;
          //else
          //nx[j]=nx[k]; 注释部分为优化.
		}
		else
			k=nx[k];
	}
}
int main()
{
	while(scanf("%s%s",p,s)!=EOF)
	{
		int pLen=strlen(p);
		int sLen=strlen(s);
		for(int i=0;i<sLen;i++)
			p[pLen+i]=s[i];
		p[pLen+sLen]='\0';
		getnext(p);
		if(nx[pLen+sLen]>min(pLen,sLen))
			nx[pLen+sLen]=min(pLen,sLen);
		for(int i=0;i<nx[pLen+sLen];i++)
			printf("%c",p[i]);
		if(nx[pLen+sLen]==0)
		{
			printf("0\n");
			continue;
		}
		printf(" %d\n",nx[pLen+sLen]);
	}	
	return 0;
}
