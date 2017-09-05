#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int mod=1e9+7;
int main()
{
	bool vis[400][400]={0};
	int n;
	long long a[400][400],b[400];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			a[i][j]=b[i]*b[j];
			long long t=sqrt(a[i][j]);
			if(t*t==a[i][j])
				vis[i][j]=1;
		}
	long long cnt[400]={0};
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i!=j&&vis[i][j])
				cnt[i]++;
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;)
	}
	return 0;
}
