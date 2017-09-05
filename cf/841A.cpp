#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,k,ans[40]={0};
	char s[200];
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	for(int i=0;i<n;i++)
	{
		ans[s[i]-'a']++;
	}
	bool f=0;
	for(int i=0;i<26;i++)
	{
		if(ans[i]>k)
			f=1;
	}
	if(f==1)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
