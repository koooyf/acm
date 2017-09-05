#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N100010
	typedef long long LL;
	LL mp[105][105];
int main()
{
	int x,y,n,m;
	LL k;
	cin>>n>>m>>k>>x>>y;
	LL mi=-1,ma =-1;
	if(n==1)
	{
		LL yu=k%m;
		LL cnt=k/m;
		for(int i=1;i<=m;i++)
			mp[1][i]+=cnt;
		for(int i=1;i<=m;i++)
			if(yu) mp[1][i]++,yu--;
	}
	else
	{
	LL num=(n+n-2)*m;
	LL cnt=k/num;
	LL yu=k%num;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)		
			if(i==1||i==n) mp[i][j]+=cnt;
			else mp[i][j]+=cnt*2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(yu) mp[i][j]++,yu--;
		for(int i=n-1;i>=1;i--)
			for(int j=1;j<=m;j++)
				if(yu) mp[i][j]++,yu--;
	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
		 if(ma<mp[i][j]) ma=mp[i][j];
		 if(mi==-1||mi>mp[i][j]) mi=mp[i][j];
		}
	}
	printf("%I64d %I64d %I64d\n",ma,mi,mp[x][y]);
	return 0;
}
