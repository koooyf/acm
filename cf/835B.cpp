#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char s[20000005];
long long ans[15]={0};
int main()
{
	long long n,sum=0;
	scanf("%lld",&n);
	scanf("%s",s);
	long long t=strlen(s);
	for(long long i=0;i<t;i++)
	{
		sum+=s[i]-'0';
		ans[s[i]-'0']++;	
	}
//	printf("%lld\n",sum);
	long long p=0,cnt=0,cc=0;
	if(sum>=n)
	{
		printf("0\n");
	}
	else
	{
		p=n-sum;
		for(int i=0;i<=8;i++)
		{
			for(int j=1;j<=ans[i];j++)
			{
				cnt+=(9-i);
				cc++;
				if(cnt>=p)
					break;
			}
			if(cnt>=p)
				break;
		}
		printf("%lld\n",cc);
	}
	return 0;
}
