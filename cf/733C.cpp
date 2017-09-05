#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,a[550],b[550],k,c[550][550]={0};
	bool flag=0,f[550][550]={0};
	memset(c,0,sizeof(c));
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&b[i]);
		sum+=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		c[i][i]=a[i];f[i][i]=1;
		for(int j=i+1;j<=n;j++)
		{
			flag=0;
			for(int k=i+1;k<=j;k++)
			{
				if(a[k]!=a[k-1])
					flag=1;
				c[i][k]=c[i][k-1]+a[k];
			}
			f[i][j]=flag;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(c[i][j]==b[ans]&&f[i][j]==1)
			{
				ans++;
				i=j+1;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//		for(int j=i;j<=n;j++){
//			printf("f[%d][%d]=%d\n",i,j,f[i][j]);
//			printf("c[%d][%d]=%d\n",i,j,c[i][j]);}
	if(ans==k+1&&c[1][n]==sum)
	{
		printf("YES\n");
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(c[i][j]==b[tot+1]&&f[i][j]==1)
				{
					 int mx,where;
					 mx=0;where=i;
					for(int k=i;k<=j;k++)
					{
						if(a[k]>mx)
						{
							mx=a[k];
							where=k;
						}
					}
					int ii=tot+1;
					int jj=j-i+1+tot;
					if(where==i&&a[where]==a[where+1]&&where+1<=j)
					{
						while(a[where]==a[where+1]&&where+1<=j)
						{
							where++;
						}
						where=where-i+1+tot;
					for(int k=where;k<jj;k++)
						printf("%d R\n",where);
					for(int k=where;k>ii;k--)
						printf("%d L\n",k);
					}
					else
					{
						where=where-i+1+tot;
						for(int k=where;k>ii;k--)
							printf("%d L\n",k);
						for(int k=where;k<jj;k++)
							printf("%d R\n",tot+1);
					}
					i=j+1;
					tot++;
				}
			}
		}
	}
	else printf("NO\n");
	return 0;
}
