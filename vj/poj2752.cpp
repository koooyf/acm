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
	int a[400005];
	while(scanf("%s",p)!=EOF)
	{
		int id=1;
		getnext();
		int len=strlen(p);
		 a[id]=len;
		while(nx[len])
		{
			id++;
			a[id]=nx[len];
			len=nx[len];
		}
		printf("%d",a[id]);
		for(int i=id-1;i>=1;i--)
			printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}
