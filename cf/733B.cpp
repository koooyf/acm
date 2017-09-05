#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int n,l[100005],r[100005],lsum,rsum;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		lsum=0;rsum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&l[i],&r[i]);
			rsum+=r[i];lsum+=l[i];
		}
		int mx=0,where=0;
		mx=abs(lsum-rsum);
		for(int i=1;i<=n;i++)
		{
			int rrsum,llsum;
			rrsum=rsum-r[i]+l[i];
			llsum=lsum-l[i]+r[i];
			if(abs(llsum-rrsum)>mx)
			{
				mx=abs(llsum-rrsum);
				where=i;
			}
		}
		printf("%d\n",where);
	}
	return 0;
}
