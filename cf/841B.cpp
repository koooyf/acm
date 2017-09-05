#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,a[1000005];
	long long ans=0;
	bool f=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans=(a[i]+ans)%2;
		if(ans==1)
			f=1;
	}
	if(ans)
	{
		printf("First\n");
	}
	else
	{
		if(f)
			printf("First\n");
		else
			printf("Second\n");
	}
	return 0;
}

