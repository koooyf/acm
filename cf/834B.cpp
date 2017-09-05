#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char s[10000050];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int maxx[300],minx[300];
	scanf("%s",s);
	int t=strlen(s);
	for(int i=0;i<100;i++)
	{
		maxx[i]=-1;
		minx[i]=1000005;
	}
	for(int i=0;i<t;i++)
	{	
		if(i>maxx[s[i]-'A'])
			maxx[s[i]-'A']=i;
		if(i<minx[s[i]-'A'])
			minx[s[i]-'A']=i;
	}
	int id[1000005]={0},vis[300]={0};
	bool f=0;
	for(int i=0;i<t;i++)
	{
		if(i>=minx[s[i]-'A']&&i<=maxx[s[i]-'A']&&!vis[s[i]-'A'])
		{
			for(int j=minx[s[i]-'A'];j<=maxx[s[i]-'A'];j++)
				id[j]++;
			vis[s[i]-'A']=1;
		}
	}
	for(int i=0;i<t;i++)
	{
		if(id[i]>k)
			f=1;
	}
	if(f==1) printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
