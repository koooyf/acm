#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n,a[200];
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	if(a[n+1]>a[n])
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
