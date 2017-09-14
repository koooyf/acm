#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int nx[200005];
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
	int n;
	int ans[200005];
	char p[200005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",p);
		getnext(p);
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)
		{
			int j=i;
			if(!nx[i])
				ans[nx[i]]=(ans[nx[i]]+1)%10007;
			else
			{
				while(nx[j])
				{
					ans[nx[j]]=(ans[nx[j]]+1)%10007;
					j=nx[j];
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++)
		{
//			printf("%d\n",ans[i]);
			sum=(sum+ans[i])%10007;
		}
		printf("%d\n",(sum+n)%10007);
	}
	return 0;
}
