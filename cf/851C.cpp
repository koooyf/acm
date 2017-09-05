#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int a[1005][6];
int main()
{
	int n,cnt=0;
	int b[6],c[6];
	scanf("%d",&n);
	int vis[1005]={0};
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d%d",&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]);
	}
	if(n>243)
		printf("0\n");
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i)
					continue;
				for(int k=j+1;k<=n;k++)
				{
					if(i!=j&&j!=k&&i!=k)
					{
						for(int t=1;t<=5;t++)
						{
							b[t]=a[j][t]-a[i][t];
							c[t]=a[k][t]-a[i][t];
						}
						double ans=0,ans1=0,ans2=0;
						for(int t=1;t<=5;t++)
						{
							ans+=b[t]*c[t];
							ans1+=b[t]*b[t];
							ans2+=c[t]*c[t];
						}
						ans1=sqrt(ans1);
						ans2=sqrt(ans2);
						double r=acos(ans/(ans1*ans2));
					//	if(i==1)
					//		printf("%f\n",r);
						if(r<1.570796)
						{
							if(!vis[i])
								cnt++;
							vis[i]=1;
						}
					}
				}
			}
		}
		printf("%d\n",n-cnt);
		for(int i=1;i<=n;i++)
			if(!vis[i])
				printf("%d\n",i);

	}
	return 0;
}
