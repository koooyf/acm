#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char s[200005],p[200005],d;
int c[200005],nt[200005];
bool f[200005]={0};
int check(int mid,int tt,int t)
{
	for(int i=0;i<=mid;i++)
		f[c[i]-1]=1;
//	for(int i=0;i<t;i++)
//		printf("%d\n",f[i]);
	int j=0,sum=0;
	for(int i=0;i<tt;i++)
	{
		while(j<t)
		{
			if(f[j]==1)
			{
				j++;
				continue;
			}
			if(p[i]==s[j])
			{
				sum++;
				j++;
				break;
			}
			else 
			j++;
		}
	}
	memset(f,0,sizeof(f));
//	printf("sum=%d\n",sum);
	if(sum==tt)
		return 1;
	else
		return 0;
}
int main()
{
	int i=0;
	scanf("%s",s);
	int t=strlen(s);
	scanf("%s",p);
	int tt=strlen(p);
	for(int j=0;j<t;j++)
		scanf("%d",&c[j]);
	int l=0,r=t-1;
	while(r-l>1)
	{
		int mid=(r+l)/2;
		if(check(mid,tt,t)==1)
		{
			l=mid;
		}
		else
			r=mid;
//		printf("%d %d\n",l,r);
	}
	int ans = (check(r,tt,t)?r:l);
	if(check(ans,tt,t)==0)
		printf("0\n");
	else
		printf("%d\n",ans+1);
	return 0;
}
