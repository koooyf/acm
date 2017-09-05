#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int t,n,a[N];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int tot[N]={0};
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		memset(tot,0,sizeof(tot));
		int cnt=1,ans=1;
		tot[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				 cnt++;
				 ans=1;
				 tot[cnt]=ans;
			}
			else
			{
				ans++;
				tot[cnt]=ans;				
			}
		}
		sort(tot+1,tot+cnt+1);
		ans=0;
		if(cnt<3)
		{
			printf("0\n");
			continue;
		}
		while(tot[cnt-2])
		{
			ans+=tot[cnt-2];
			tot[cnt-1]-=tot[cnt-2];
			tot[cnt]-=tot[cnt-2];
			tot[cnt-2]=0;
			sort(tot+1,tot+cnt+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
