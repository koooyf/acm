#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int t,ans=0,i;
	bool f=0;
	char s[55];
	scanf("%s",s);
	int n=strlen(s);
	double sum=0;
	t=n;
	if(s[0]>='0'&&s[0]<='9')
		i=0;
	else if(s[0]=='-')
	{
		i=1;
		t=n-1;
		f=1;
	}
	for(;i<n;i++)
	{
		if(s[i]=='2')
			ans++;
	}
	sum=(double)ans/(double)t*100;
	if((s[n-1]-'0')%2==0)
	{
		sum=sum*2;
	}
	if(f)
		sum=sum*1.5;
	printf("%.2f%%\n",sum);	
	return 0;
}
