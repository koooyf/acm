#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	char a,b;
	int c[4]={118,60,94,62};
	int cc[4]={62,94,60,118};
	scanf("%c %c",&a,&b);
	int n;
	int aa=a,bb=b;
	scanf("%d",&n);
	bool f=0,ff=0;
	int j,k;
	for(j=0;j<=3;j++)
	{
		if(c[j]==aa)
			break;
	}
	for(k=0;k<=3;k++)
	{
		if(c[k]==bb)
			break;
	}
	int p,t;
	if(j<k)
	{
		p=k-j;
		for(int i=p;;i+=4)
		{
			if(i==n)
			{
				f=1;
				break;
			}
			if(i>n)
				break;
		}
		t=3-k;
		for(int i=j+t+1;;i+=4)
		{
			if(i==n)
			{
				ff=1;
				break;
			}
			if(i>n)
				break;
		}
		if(f==1&&ff==0)
		printf("cw\n");
		else if(f==0&&ff==1)
		printf("ccw\n");
		else
		printf("undefined\n");	
	}
	else if(j>k)
	{
		t=3-j;
		for(int i=t+k+1;;i+=4)
		{
			if(i==n)
			{
				f=1;
				break;
			}
			if(i>n)
				break;
		}
		p=j-k;
		for(int i=p;;i+=4)
		{
			if(i==n)
			{
				ff=1;
				break;
			}
			if(i>n)
				break;
		}
		if(f==1&&ff==0)
			printf("cw\n");
		else if(f==0&&ff==1)
			printf("ccw\n");
		else
			printf("undefined\n");
	}
	else if(j==k)
		printf("undefined\n");
	return 0;
}
