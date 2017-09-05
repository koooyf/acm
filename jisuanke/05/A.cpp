#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const double L=0.5772;
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		double m=(double)n;
		if(n==1)
			printf("%d\n",1);
		else
		{
			int d=n*(log(m+1)+L)+1;
			printf("%d\n",d);					
		}
	}
	return 0;
}
