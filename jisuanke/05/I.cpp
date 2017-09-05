#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double pi=3.1415926;
int main()
{
	double R,r;
	int n;
	while(scanf("%d%lf%lf",&n,&R,&r)!=EOF)
	{
		if(R==r)
		{
			if(n==1)
				printf("yes\n");
			else
				printf("no\n");
			continue;
		}
		else if(R<r)
		{
			printf("no\n");
			continue;
		}
		if(R==2*r)
		{
			if(n<=2) printf("yes\n");
			else
				printf("no\n");
			continue;
		}
		else if(R<2*r)
		{
			if(n<=1) printf("yes\n");
			else
				printf("no\n");
			continue;
		}
		double sum=((R-r)*(R-r)*2-(2*r*2*r))/(2*(R-r)*(R-r));
		double t=acos(sum);
		
		int tt=(2.0*pi)/t;
		if(tt>=n)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
