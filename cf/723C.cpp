#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,m,a[3000],ans[3000];
	bool vis[3000]={0};
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int tot=n/m;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>m) continue;
			if(ans[a[i]]>=tot) continue;
			ans[a[i]]++;
			vis[i]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			int ans1=1e9,ans2=1e9;
			for(int j=1;j<=m;j++)
			{
				if(ans[j]<ans2)
					ans2=ans[j],ans1=j;
			}
			if(ans2==tot) continue;
			cnt++;
			ans[ans1]++,a[i]=ans1;
		}
		printf("%d %d\n",tot,cnt);
		for(int i=1;i<=n-1;i++)
			printf("%d ",a[i]);
		printf("%d\n",a[n]);
	}
	return 0;
}
