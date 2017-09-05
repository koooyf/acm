#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,a,b,t;
	scanf("%d%d%d",&n,&a,&b);
	int ans=0,tot=0,cnt=0,sum=0,p=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t);
		if(t==1)
		{
			if(ans<a)
				ans++;
			else if(tot<b)
				tot++;
			else if(cnt<tot-p)
				cnt++;
			else
				sum++;
		}
		else if(t==2)
		{
			if(tot<b)
			{
				tot++;
				p++;
			}
			else
				sum+=2;			
		}
	}
	printf("%d\n",sum);
	return 0;
}
