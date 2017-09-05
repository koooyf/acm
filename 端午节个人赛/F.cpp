#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a==0)
		{
			if(b==0)
			{
				if(c!=0)
				printf("YES\n");
				else
					printf("NO\n");
			}
			else
			{
				if(c>0)
					c=-c;
				if(b<0)
					b=-b;
				if((-c)%b==0)
					printf("YES\n");
				else 
					printf("NO\n");
			}
		}
		else if(a!=0)
		{
			int n=b*b-4*a*c;
			if(n<0)
				printf("YES\n");
			else if(n>=0)
			{
				int x=sqrt(n);
				if(x*x!=n)
					printf("NO\n");
				else
				{
				if((-b+x)%(2*a)==0&&(-b-x)%(2*a)==0)
					printf("YES\n");
				else
					printf("NO\n");
				}
			}
		}

	}
	return 0;
}
