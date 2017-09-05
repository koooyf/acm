#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define mod 1000000007
vector<long long> g[1000050];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int t,k;
		scanf("%d",&t);
		for(int j=1;j<=t;j++)
		{
			scanf("%d",&k);
			g[k].push_back(i);
		}
	}
	sort(g+1,g+1+m);
	long long kk=1,ans=1;
	for(int i=2;i<=m;i++)
	{
		if(g[i]==g[i-1])
		{
			kk++;
			ans=(ans*kk)%mod;
		}
		else kk=1;
	}
	printf("%I64d\n",ans);
	return 0;
}
