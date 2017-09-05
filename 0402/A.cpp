#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,m,k,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		if(n<m)
		{
			int t=n;
			n=m;
			m=t;
		}
		bool flag=0;
		if(k+1<=m&&2*k+3<=n)
			flag=1;
		if(flag)
		{
			if(k==1)
				printf("%d\n",min(m/k+(m%k==0?0:1),5));
			else
				printf("%d\n",min(m/k+(m%k==0?0:1),4));
		}
		else
			printf("-1\n");
	}
	return 0;
}
