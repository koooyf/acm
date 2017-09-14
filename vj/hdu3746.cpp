#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int nx[100050],ans=0;
char p[100050];
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
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",p);
		getnext();
		int len=strlen(p);
		int lenth=len-nx[len];
		if(len!=lenth&&len%lenth==0)
			printf("0\n");
		else
		{
			ans=lenth-nx[len]%lenth;
			printf("%d\n",ans);
		}
	}
	return 0;
}
