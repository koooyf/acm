#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int s,v1,v2,t1,t2;
	scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
	int sum=t1*2+s*v1;
	int ans=t2*2+s*v2;
	if(sum<ans)
		printf("First\n");
	else if(sum>ans)
		printf("Second\n");
	else
		printf("Friendship\n");
	return 0;
}
