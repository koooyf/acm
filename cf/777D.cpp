#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
string s[500010];
string ans[500010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	cin>>s[i];
	ans[n]=s[n];
	for(int i=n-1;i>=1;i--)
	{
		if(ans[i+1]>=s[i])
		{
			ans[i]=s[i];
			continue;
		}
		int j;
		int a=s[i].size(),b=ans[i+1].size();
		int t=min(a,b);
		for(j=0;j<t;j++)
		{
			if(s[i][j]>ans[i+1][j])
			{
				break;
			}
		}
		for(int k=0;k<j;k++) ans[i]+=s[i][k];
	}
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<endl;	
	return 0;
}
