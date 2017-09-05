#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct matri
{
	long long m[4][4];
};
matri mat(matri a,matri b)
{
	matri c;
	long long mod=1000000007;
	for(int i=0;i<=3;i++)
	for(int j=0;j<=3;j++)
	{
		c.m[i][j]=0;
		for(int k=0;k<=3;k++)
			c.m[i][j]+=(a.m[i][k]*b.m[k][j])%mod;
		c.m[i][j]%=mod;
	}
	return c;
}
matri does(matri b,int n)
{
	matri a=
	{
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		0,0,0,1
	};
	while(n)
	{
		if(n&1)
			a=mat(a,b);
		n=n>>1;
		b=mat(b,b);
	}
	return a;
}
int main()
{
	long long a,b,c;
	while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
	{
	if(c==1)
	{
		printf("%lld\n",a);
	}
	else{
		matri d=
		{
			1,1,1,0,
			1,0,0,0,
			0,0,0,1,
			0,0,-1,0
		};
		d=does(d,c-2);
		int mod=1000000007;
		long long int sum=((d.m[0][0]*b%mod+d.m[0][1]*a%mod)%mod+mod-d.m[0][3])%mod;
		printf("%lld\n",sum);
      	}
	}
	return 0;
}
