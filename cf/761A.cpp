#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==0&&b==0)
		printf("NO\n");
	else{
	if((a+b)%2==0)
	{
		if(a==b)
			printf("YES\n");
		else
			printf("NO\n");
	}
	else
	{
		if(a-b==1||b-a==1)
			printf("YES\n");
		else
			printf("NO\n");
	}}
	return 0;
}
