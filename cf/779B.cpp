#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char a[100];
	int k,sum=0,tot=0;
	scanf("%s%d",a,&k);
	int t=strlen(a);
	if(k+1>t)
		printf("%d\n",t-1);
	else 
	{
		int p=0;
		for(int i=0;i<t;i++)
		{
			if(a[i]=='0')
				p++;
		}
		for(int i=t-1;i>=0;i--)
		{
			if(sum==k)
				break;
			if(a[i]=='0')
				sum++;
			else
			{
				tot++;			
			}
		}
	   if(p>=k)
	    printf("%d\n",tot);
	   else
		printf("%d\n",t-1);
	}
	return 0;
}
