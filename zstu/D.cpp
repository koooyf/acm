#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int atk[200006],pos[60000],ap[60000];
int main()
{
	int t,n,m,q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)
			scanf("%d",atk[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",pos[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",ap[i]);
		int ans=0;
		for(int i=1;i<=q;i++)
		{
			int pl,pr;
			scanf("%d%d",&pl,&pr);
			pl=pl^ans,pr=pr^ans;
			if(pl>=pr)
			{
				int p=pl;
				pl=pr;
				pr=p;
			}
			
		}
	}
	return 0;
}
