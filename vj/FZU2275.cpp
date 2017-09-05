#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+10;
int nx[N];
int kmpsearch(char *s,char *p)
{
	int i=0;
	int j=0;
	int sLen=strlen(s);
	int pLen=strlen(p);
	while(i<sLen&&j<pLen)
	{
		if(j==-1||s[i]==p[j])
		{
			j++,i++;
		}
		else
			j=nx[j];
	}
	if(j==pLen)
	{
		return i-j;
	}
	else
		return -1;
}
void getnext(char *p)
{
	memset(nx,0,sizeof(nx));
	int pLen=strlen(p);
	int k=-1,j=0;
	nx[0]=-1;
	while(j<pLen-1)
	{
		if(k==-1||p[k]==p[j])
		{
			j++;
			k++;
			if(p[k]!=p[j])
				nx[j]=k;
			else
				nx[j]=nx[k];
		}
		else
			k=nx[k];
	}
}
int main()
{
	int n;
	char s[N],p[N],s1[N];
	scanf("%d",&n);
	while(n--)
	{
		bool f=0;
		scanf("%s %s",s,p);
		int sLen=strlen(s);
		int pLen=strlen(p);
		if(strcmp(p,"0")==0)
		{
			printf("Alice\n");
			continue;
		}
		if(sLen<pLen)
		{
			printf("Bob\n");
			continue;
		}
		else
		{
			for(int i=0;i<sLen;i++)
			{
				s1[sLen-1-i]=s[i];
			}
			s1[sLen]='\0';
			getnext(p);
			if(kmpsearch(s,p)!=-1)
				f=1;			
			if(kmpsearch(s1,p)!=-1)
				f=1;
			if(f)
				printf("Alice\n");
			else
				printf("Bob\n");
		}
	}
	return 0;
}
