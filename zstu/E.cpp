#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int data[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
void check(int y)
{
	if((y%4==0&&y%100!=0)||y%400==0)
		data[2]=28;
	else 
		data[2]=29;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int y,m,d;
		scanf("%d%d%d",&y,&m,&d);
		int sum=0;
		while(true)
		{
			if(y==2017&&m==10&&d==28)
				break;
			check(y);
			if(d==data[m]+1)
			{
				m++;
				d=1;
			}
			if(m==13)
			{
				y++;
				m=1;
			}
			d++;
			sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
