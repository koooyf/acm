#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
long long m;
struct mix{
	long long a[2][2];
	mix operator * (const mix &now) const
	{
		mix c;
		memset(c.a,0,sizeof(c.a));
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				for(int k=0;k<2;k++)
				{
					c.a[i][j]=(m+c.a[i][j]+now.a[i][k]*a[k][j])%m;		
				}
			}
		}
		return c;
	}
};
mix mod_pow(mix a, long long b)
{
	mix ans;
	ans.a[0][0]=1,ans.a[0][1]=0,ans.a[1][0]=0,ans.a[1][1]=1;
	while(b)
	{
		if(b&1)
			ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main()
{
	long long a,n,b;
	while(scanf("%lld%lld%lld%lld",&a,&b,&n,&m)!=EOF)
	{
		mix c;
		c.a[0][0]=2*a,c.a[0][1]=-(a*a-b),c.a[1][0]=1,c.a[1][1]=0;
		mix d=mod_pow(c,n);
		printf("%lld\n",(((int)ceil(a+sqrt((double)b))*d.a[1][0]+2*d.a[1][1]%m+m)%m));
	}	
	return 0;
}
