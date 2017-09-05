#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	char a[10];
	int b[10]={0};
	int ans1=0,ans2=0,cnt=0;
	scanf("%s",a);
	for(int i=0;i<=2;i++)
	{	
		ans1+=a[i]-'0';
		b[i]=a[i]-'0';
		ans2+=a[i+3]-'0';
		b[i+3]=a[i+3]-'0';
	}
	int ans3=ans1-ans2,i,j,ans;
//	printf("%d\n",ans3);
	if(ans3>0)
	{
		ans=ans3;
		for(int i=3;i<=5;i++)
		{
			b[i]=9-b[i];
		}
		sort(b,b+6);
		for(int i=5;i>=0;i--)
		{
			if(ans<=b[i])
			{
				cnt++;
				break;
			}
			else
			{
				ans-=b[i];
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	else if(ans3<0)
	{
		ans=ans3;
		for(int i=0;i<=2;i++)
			b[i]=9-b[i];
		sort(b,b+6);
		for(int i=5;i>=0;i--)
		{
			if(-ans<=b[i])
			{
				cnt++;
				break;
			}
			else
			{
				ans+=b[i];
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	else
		printf("0\n");
	return 0;
}
