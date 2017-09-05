#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[20];
	int ans=0;
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n/2;i++)
	{
		if(s[i]!=s[n-i+1])
			ans++;
	}
	if(ans>1||(ans==0&&n%2==0))
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
