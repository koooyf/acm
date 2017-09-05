#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int sg[10005];
bool has[10005];
void getsg(int *f,int n,int k)
{
	memset(sg,0,sizeof(sg));
	for(int i=1;i<=n;i++)
	{
		memset(has,0,sizeof(has));
		for(int j=1;j<=k;j++)
		{
			if(i-f[j]>=0)
			 has[sg[i-f[j]]]=1;
		}
		for(int j=0;j<=n;j++)
		{
			if(has[j]==0)
			{
				sg[i]=j;
				break;
			}
		}		
	}	
}
int main()
{
	int k,m,l,h,sum;
	while(scanf("%d",&k)!=EOF)
	{
		int s[200];
		if(k==0)
			break;
		for(int i=1;i<=k;i++)
			scanf("%d",&s[i]);
		sort(s+1,s+1+k);
		getsg(s,10003,k);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&l);
			sum=0;
			for(int i=1;i<=l;i++)
			{
				scanf("%d",&h);
				sum=sum^sg[h];
			}
			if(sum==0)
				printf("L");
			else
				printf("W");
		}
		printf("\n");
	}
	return 0;
}
