#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%d %d\n",(m-2*n)/2,n-(m-2*n)/2);
	}
	return 0;
}
