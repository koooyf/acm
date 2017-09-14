#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int nx[100005];
char ss[100005],s[100005],pp[100005],c[100005];
void getnext(char *p)
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		scanf("%s",pp);
		int sLen=strlen(s);
		for(int i=0;i<sLen;i++)
			ss[s[i]-'a']=i;
		strcpy(c,pp);
		int pLen=strlen(c);
		int n=(pLen+1)/2;
		for(int i=n;i<pLen;i++)
		{
			c[i]=s[c[i]-'a'];
		}	
		getnext(c);
		int k=pLen;
		while(nx[k]>pLen-n)
		{
			k=nx[k];	
		}
//		printf("%d\n",nx[k]);
			for(int j=0;j<pLen-nx[k];j++)
				printf("%c",pp[j]);
			for(int j=0;j<pLen-nx[k];j++)
				printf("%c",ss[pp[j]-'a']+'a');
		printf("\n");
	}
	return 0;
}
