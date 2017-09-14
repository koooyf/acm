#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int nx[1000050],ans=0;
char p[1000050];
void getnext()
{
	int k=-1,j=0;
	nx[0]=-1;
	int pLen=strlen(p);
	while(j<pLen)
	{
		if(k==-1||p[k]==p[j])
		{
			j++;
			k++;
			nx[j]=k;
		}
		else
			k=nx[k];
	}
}
int n;
int main()
{
	int ca=0;
	while(true)
	{
		ca++;
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%s",p);
		getnext();
		printf("Test case #%d\n",ca);
		for(int i=1;i<=n;i++)
		{
//			printf("%d\n",nx[i]);
			if(!nx[i])
				continue;
			else
			{
				int lenth=i-nx[i];
//				printf("lenth=%d %d\n",lenth,i);
				if(!(i%lenth))
				{
					printf("%d %d\n",i,i/lenth);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
