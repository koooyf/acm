#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 20000005
char a[N];
int main()
{
	int n,lenD=0,lenR=0;
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='D')
			lenD++;
		else
			lenR++;
	}
	int d=0,r=0;
	for(int i=1;i<=n&&lenD>0&&lenR>0;i++)
	{
		if(a[i]=='D')
		{
			if(r>0)
			{
				lenD--;
				r--;				
			}
			else
			{
				d++;
				a[++n]='D';			
			}		
		}
		else
		{
			if(d>0)
			{
				lenR--;
				d--;
			}
			else
			{
				r++;	
				a[++n]='R';
			}
		}
	}
	if(lenD==0)
		printf("R\n");
	else
		printf("D\n");
	return 0;
}
