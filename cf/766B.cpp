#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,a[100005];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	bool flag=0;
	int l=0,r=1;
	for(int i=2;i<n;i++)
	{
		if(a[i]>=a[l]+a[r])
		{
			l++;
			r++;
		}
		else
		{
			flag=1;
			break;
		}		
	}
	if(flag==1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

