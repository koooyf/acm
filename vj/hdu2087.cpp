#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int t,n,m,nx[10005],ans=0,nt[10005];
char s[1000005],p[10005];
void kmpsearch()
{
	int i=0;
	int j=0;
	int sLen=strlen(s);
	int pLen=strlen(p);
	while(i<sLen)
	{
		if(j==-1||s[i]==p[j])
			j++,i++;
		else
			j=nx[j];
		if(j==pLen)
		{
			ans++;
			j=0;
		}
	}
}
void getnext()
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
		ans=0;
		scanf("%s",s);
		if(strcmp(s,"#")==0)
			break;
		scanf("%s",p);
		getnext();
		kmpsearch();
		printf("%d\n",ans);
	}
	return 0;
}
