#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,k,a[200];
	int sum=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
//	printf("sum=%d\n",sum);
	int ans=0;
	bool f=0;
	if(double(sum)/double(n)-sum/n>=0.5)
	{
//		printf("%f %d\n",double(sum)/double(n),sum/n);
		if(sum/n+1==k)
		{
			printf("0\n");
			f=1;
		}
	}
	else if(sum/n==k)
	{
		printf("0\n");
		f=1;
	}
	if(!f)
	{
	for(int i=1;;i++)
	{
		sum+=k;
		if(double(sum)/double(n+i)-sum/(n+i)>=0.5)
		{
//			printf("%d %lf %d\n",sum,double(sum)/double(n+i),sum/(n+i));
			if(sum/(n+i)+1==k)
			{
				ans=i;
				break;
			}
		}
		else if(sum/(n+i)==k)
		{
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	}
	return 0;
}
