#	include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define mod 1000000007
int cnt[2][100005];
bool vis[100005];
void dfs(int i,int r,int *a,int id)
{
	if(vis[i])
	{
		cnt[id][r]++;
		return ;		
	}
	vis[i]=1;
	dfs(a[i],r+1,a,id);
}
int main()
{
	int n,m,a[100005],b[100005],ca=0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ca++;
		memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		for(int i=0;i<m;i++)
			if(!vis[i]) dfs(i,0,b,0);
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
			if(!vis[i]) dfs(i,0,a,1);
		long long ans=1,sum=0;
		for(int i=1;i<=n;i++)
		{
			sum=0;
			if(cnt[1][i])
			{
				for(int j=1;j*j<=i;j++)
				{
					if(i%j==0)
					{
						sum=(sum+cnt[0][j]%mod*j%mod)%mod;
						if(j*j!=i)sum=(sum+cnt[0][i/j]%mod*(i/j)%mod)%mod;				
					}
				}
				for(int j=1;j<=cnt[1][i];j++)
					ans=ans*sum%mod;
			}			
		}
		printf("Case #%d: %lld\n",ca,ans);
	}	
	return 0;
}
