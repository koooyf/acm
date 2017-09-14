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
	while(scanf("%s",p)!=EOF)
	{
		getnext();
		int len=strlen(p);
		for(int i=1;i<=len;i++)
		{
			if(!nx[i])
				continue;
			else
			{
				printf("%d\n",i-nx[i]);
				break;
			}
		}
	}
	return 0;	
}
