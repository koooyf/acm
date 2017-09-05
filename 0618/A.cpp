#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int i,e,a,q1,q2,q3,n,k=0;
	while(true)
	{
		k++;
		scanf("%d%d%d%d%d%d%d",&i,&e,&a,&q1,&q2,&q3,&n);
		if(i==-1&&e==-1&&a==-1&&q1==-1&&q2==-1&&q3==-1)
			break;
		long long x=(n-i)/q1;
		for(long long j=x;;j++)
		{
			long long sum=i+j*q1;
			if((sum-e)%q2==0&&(sum-a)%q3==0&&sum>n)
			{
				printf("Case %d : %lld seconds .\n",k,sum-n);
				break;
			}
		}
	}
	return 0;
}


