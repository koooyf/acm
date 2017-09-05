#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,a[200];
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	int tot=8*n;
	for(int i=1;i<=k;i++)
	{
		int ans=a[i]%8;
		if(ans==2||ans==0||ans==6)
		{
			tot-=a[i];		
		}
		else if(ans==1||ans==3||ans==4||ans==5||ans==7)
		{
			tot=tot-a[i]-1;
		}
	}
	if(tot>=0)
		printf ("YES\n");
	else
		printf ("NO\n");
	return 0;
}
