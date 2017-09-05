#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(n-k>=3)
	{
		int t=k-2,i,id;
		for(i=0;;i++)
		{
			if(t*i+2*i+1>=n-k)
			{
				id=1;
				break;
			}
			else if(t*i+2*i+2>=n-k)
			{
				id=2;
				break;
			}
		}
		int j,p,tt,ttt,h;
		bool flag=0;
		if(id==1)
		{
			printf("%d\n",2*i+2);
			for( j=1;j<=2*i+2;j++)
				printf("%d %d\n",j,j+1);
			 tt=((n-k)-2*i-1)/i;
			 h=tt;
			 ttt=(n-k-2*i-1)%i;
			while(tt)
			{
				printf("%d %d\n",(2*i+3)/2+1,j+1);
				for(p=1;p<=i&&p+j+1<=n;p++)
					printf("%d %d\n",p+j,p+j+1);
				tt--;
				if(p+j+1>n) break; 
				j=j+1+i;		
			}
			if(ttt>0)
			{
				printf("%d %d\n",(2*i+3)/2+1,j+1);
				for(p=1;p<=ttt;p++)
					printf("%d %d\n",p+j,p+j+1);
				for(p=1;p<=t-h-1;p++)
					printf("%d %d\n",(2*i+3)/2+1,p+ttt+j+1);
			}
			else
			{
				for(p=1;p<=t-h;p++)
					printf("%d %d\n",(2*i+3)/2+1,p+j);
			}
		}
		if(id==2)
		{
			printf("%d\n",2*i+3);
			for(j=1;j<=2*i+3;j++)
				printf("%d %d\n",j,j+1);
			tt=(n-k-2*i-2)/i;
			ttt=(n-k-2*i-2)%i;
			h=tt;
			while(tt)
			{
				printf("%d %d\n",(2*i+4)/2,j+1);
				for(p=1;p<=i&&p+j+1<=n;p++)
					printf("%d %d\n",p+j,p+j+1);
				tt--;
				if(p+j+1>n) break;
				j=j+1+i;
			}
			if(ttt>0)
			{
				printf("%d %d\n",(2*i+4)/2,j+1);
				for(p=1;p<=ttt;p++)
					printf("%d %d\n",p+j,p+j+1);
				for(p=1;p<=t-h-1;p++)
					printf("%d %d\n",(2*i+4)/2,ttt+j+1+p);
			}
			else
				for(p=1;p<=t-h;p++)
					printf("%d %d\n",(2*i+4)/2,p+j);
		}
	}
	else if(n-k==2)
	{
		printf("3\n");
		printf("1 2\n");
		printf("2 3\n");
		printf("3 4\n");
		for(int i=5;i<=n;i++)
		printf("3 %d\n",i);
	}
	else if(n-k==1)
	{
		printf("2\n");
		printf("1 2\n");
		printf("2 3\n");
		for(int i=4;i<=n;i++)
			printf("2 %d\n",i);
	}
	return 0;
}
