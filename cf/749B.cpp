#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int x[4],y[4];
	for(int i=1;i<=3;i++)
		scanf("%d %d",&x[i],&y[i]);
	for(int i=1;i<=3;i++)
	{
		for(int j=i+1;j<=3;j++)
		{
			if(x[i]>x[j])
			{
				int t=x[i];
				int p=y[i];
				x[i]=x[j];
				y[i]=y[j];
				x[j]=t;
				y[j]=p;
			}
		}
	}
	//for(int i=1;i<=3;i++)
	//	printf("%d %d\n",x[i],y[i]);
	int chang=x[3]-x[1];
	int gao=y[3]-y[1];
	printf("3\n");
	printf("%d %d\n",x[2]+chang,y[2]+gao);
	printf("%d %d\n",x[2]-chang,y[2]-gao);
	chang=x[3]-x[2],gao=y[2]-y[1];
	printf("%d %d\n",x[1]+chang,y[3]-gao);
	return 0;
}
