#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		char a[200];
		stack<char>qqq;
		gets(a);
		int len=strlen(a);
		for(int i=0;i<len;i++)
		{
			if(qqq.size()!=0)
			{
	  			if(((qqq.top()=='('&&a[i]==')')||(qqq.top()=='['&&a[i]==']')))
				{
					qqq.pop();
					continue;			
				}
			}
			qqq.push(a[i]);
		}
		if(qqq.size()==0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
