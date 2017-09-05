#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int u;
	int v;
};
node ans[100005];
int tot[100005]={0};
int main()
{
	int n,sum=0,co[100005];
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
		scanf("%d%d",&ans[i].u,&ans[i].v);
	for(int i=1;i<=n;i++)
		scanf("%d",&co[i]);
	for(int i=1;i<=n-1;i++)
	{
		if(co[ans[i].u]!=co[ans[i].v])
		{
			sum++;
			tot[ans[i].u]++;
			tot[ans[i].v]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(sum==tot[i])
		{
			printf("YES\n");
			printf("%d\n",i);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
