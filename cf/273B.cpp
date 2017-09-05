#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n;
	char a[300];
	bool f=0,ff=0,fff=0;
	scanf("%d",&n);
	scanf("%s",a);
	int ans=0,sum=0,mx=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='(')
		{
			f=1;
			ff=0;
			fff=0;
			mx=max(mx,ans);
			ans=0;
		}
		if(a[i]==')')
		{
			f=0;
			ff=0;
			fff=0;
		}
		if(f==0)
		{
			if(a[i]=='_')
				fff=1;
			if(fff==0&&a[i]!=')')
				ans++;
			if(fff==1)
			{
				mx=max(mx,ans);
				ans=0;
				fff=0;
			}
		}
		else if(f==1)
		{
			if(ff==0&&a[i]!='('&&a[i]!=')'&&a[i]!='_')
			{
				ff=1;
				sum++;
			}
			else if(ff==1&&a[i]=='_')
			{
				ff=0;
			}
		}
		mx=max(mx,ans);
	}
	printf("%d %d\n",mx,sum);
	return 0;
}
