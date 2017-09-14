#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int nx[200];
int kmpsearch(char *s,char *p)
{
	int i=0;
	int j=0;
	int sLen=strlen(s);
	int pLen=strlen(p);
	while(i<sLen&&j<pLen)
	{
		if(j==-1||s[i]==p[j])
			j++,i++;
		else
			j=nx[j];
	}
	if(j==pLen)
		return i-j;
	return -1;
}
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
	int n,t;
	char ss[105],s[105][105],p[105];
	scanf("%d",&t);
	while(t--)
	{
		int maxx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]);
		int len=strlen(s[1]);
		for(int k=1;k<=len;k++)
		{
			for(int i=0;i+k-1<len;i++)
			{
				bool flag=0;
				for(int j=0;j<k;j++)
				{
					p[j]=s[1][i+j];
				}
				p[k]='\0';
				//printf("%s\n",p);
				memset(nx,0,sizeof(nx));
				getnext(p);
				for(int j=2;j<=n;j++)
				{
					int sLen=strlen(s[j]);
					for(int r=0;r<sLen;r++)
						ss[r]=s[j][sLen-1-r];
					ss[sLen]='\0';
					//printf("%s\n",ss);
					if(kmpsearch(s[j],p)==-1&&kmpsearch(ss,p)==-1)
						flag=1;
				}
				if(!flag)
					maxx=k;
			}
		}
		printf("%d\n",maxx);
	}
	return 0;
}
