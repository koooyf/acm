#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
bool flag=0;
int a[100],b[100];
int main()
{
	int n,L;
	scanf("%d%d",&n,&L);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+n);
	for(int i=0;i<L;i++)
	{
		int ans=0;
		for(int j=0;j<n;j++)
		{
			int cnt=0;
			if(a[j]<i)
				cnt=L-(i-a[j]);
			else
				cnt=a[j]-i;
			for(int k=0;k<n;k++)
			{
				if(b[k]==cnt)
				{
					ans++;
					break;
				}
			}	
		}
//		printf("%d\n",ans);
		if(ans==n)
			flag=1;		
	}
	if(flag==1) printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
