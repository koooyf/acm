#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,m,a[200],l,r;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&l,&r);
			int tot=0;
			for(int j=l;j<=r;j++)
				tot+=a[j];
			if(tot>=0)
				sum+=tot;
		}		
		printf("%d\n",sum);
	}
	return 0;
}
