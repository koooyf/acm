#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char a[100005];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",a);
	int sum=0,tot=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='A')
			sum++;
		else tot++;
	}
	if(sum>tot)
		printf("Anton\n");
	else if(sum<tot)
		printf("Danik\n");
	else 
		printf("Friendship\n");
	return 0;
}
