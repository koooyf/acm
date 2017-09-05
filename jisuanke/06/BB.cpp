#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,num[200],a[200][200],sum=0,ans=0;
int flag=0;
void dfs(int k,int cnt,int tot)
{
	if(flag==2)
		return ;
	if(k<=n+1&&tot==sum)
	{
		if((!flag||flag==1)&&cnt>ans-cnt)
			flag=2;
		else if(!flag&&cnt==ans-cnt)
			flag=1;
		return ;
	}
	if(k>n+1)
		return ;
	for(int i=1;i<=sum&&i<=num[k];i++)
	{
		dfs(k+1,cnt+a[k][i],tot+i);
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		sum=0,ans=0;
		flag=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
			for(int j=1;j<=num[i];j++)
			{
				scanf("%d",&a[i][j]);
				ans+=a[i][j];
				a[i][j]+=a[i][j-1];
			}	
		}
		if(sum%2)
			sum=sum/2+1;
		else
			sum=sum/2;
		dfs(1,0,0);
		if(flag==2)
			printf("win\n");
		else if(flag==1)
			printf("tie\n");
		else 
			printf("lose\n");
	}
	return 0;
}
