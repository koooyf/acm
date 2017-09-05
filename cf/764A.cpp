#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,m,z,ans=0;
	scanf("%d%d%d",&n,&m,&z);
	for(int i=1;i<=z;i++)
	{
		if(i%n==0&&i%m==0)
			ans++;
	}
	printf("%d\n",ans);
	return 0;
}
