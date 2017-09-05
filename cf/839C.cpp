#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
int vis[100005]={0};
vector<int>a[100005];
double ans=0;
void dfs(int u,int len,long long id)
{
	if(a[u].size()==1&&u!=1)
	{
		ans+=double(1.0/double(id))*len;
		return ;
	}
	for(int i=0;i<a[u].size();i++)
	{
		int v=a[u][i];
		long long k=id*a[u].size();
		long long kk=id*(a[u].size()-1);
		if(vis[v]==0)
		{
			vis[v]=1;
//			printf("v=%d u=%d size=%lld\n",v,u,k);
			if(u==1)
			dfs(v,len+1,k);
			else
			dfs(v,len+1,kk);
		}
	}
}
int main()
{
	int n,u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	vis[1]=1;
	dfs(1,0,1);
	printf("%.15f\n",ans);
	return 0;
}
