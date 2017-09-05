#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
bool f[10000050]={0};
int a[10000],n;
int aabs(int x)
{
	if(x>=0)
		return x;
	else return -x;
}
int main()
{
	int n,maxx=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			f[aabs(a[i]-a[j])]=1;
		}
	}
	for(int i=n;i<=maxx;i++)
	{
		bool flag=0;
		for(int j=1;i*j<=maxx;j++)
		{
			if(f[i*j])
			{
				flag=1;
				break;
			}
		}
		if(flag==1) continue;
		printf("%d\n",i);
		break;
	}
	return 0;
}
