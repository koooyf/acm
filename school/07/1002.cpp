#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,sum=0;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
	for(int i=1;i<=n;i++)
		sum=sum^i;
	 printf("sum=%d\n",sum);
	}
	return 0;
}
