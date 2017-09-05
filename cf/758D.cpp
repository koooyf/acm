#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	long long base;
	char k[200];
	scanf("%lld",&base);
	scanf("%s",k);
	int len=strlen(k);
	long long ans=0,mul=1,tmp;
	int st,ed=len-1;
	while(ed>=0)
	{
		for(int i=0;i<=ed;i++)
		{
			if(ed-i>15) continue;
			tmp=0;
			for(int j=i;j<=ed;j++)
			{
				tmp=tmp*10+k[j]-'0';
			}
			if(tmp<base) 
			{
				st=i;
				break;
			}
		}
		while(st<ed&&k[st]=='0') st++;
		ans+=mul*tmp;
		mul=mul*base;
		ed=st-1;
	}
	printf("%lld\n",ans);
	return 0;
}
