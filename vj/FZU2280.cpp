#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
struct string
{
	char ss[2000];
	int w;
	int id;
}s[2000];
bool cmp(string a , string b)
{
	if(strcmp(a.ss,b.ss)<0)
		return 1;
	else
		return 0;
}
int main()
{
	int t,n;
	char ss[2000];
	scanf("%d",&t);
	while(t--)
	{
		int dp[2000];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",ss);
			int tt=strlen(ss);
			for(int j=0;j<tt;j++)
			{
				s[i].ss[j]=ss[tt-1-j];
			}
			s[i].ss[tt]='\0';
			scanf("%d",s[i].w);
			s[i].id=i;
		}

	}
	return 0;
}
