#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,ans[100]={0},maxsum=0,minsum=0,tot[100]={0};
	char a[2000],b[2000];
	scanf("%d",&n);
	scanf("%s",a);
	scanf("%s",b);
	for(int i=0;i<n;i++)
	{
	ans[b[i]-'0']++;
	tot[b[i]-'0']++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=9;j++)
		{
		if(ans[a[i]-'0'+j]>0)
		{
			maxsum++;
			ans[a[i]-'0'+j]--;
			break;
		}
		}
		for(int j=0;j<=9;j++)
		{
			if(tot[a[i]-'0'+j]>0)
			{
				minsum++;
				tot[a[i]-'0'+j]--;
				break;
			}
		}
	}
	printf("%d\n",n-minsum);	
	printf("%d\n",maxsum);
	return 0;
}
