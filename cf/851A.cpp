#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,k,t;
	scanf("%d%d%d",&n,&k,&t);
	if(t<=k)
		printf("%d\n",t);
	else if(t>k&&t<=n)
		printf("%d\n",k);
	else
		printf("%d\n",k-(t-n));
	return 0;
}
