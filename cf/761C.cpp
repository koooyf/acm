#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int n,m;
	char a[100][100];
	int b[100][3];
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",a[i]);
	for(int i=0;i<100;i++)
	{
		b[i][0]=1000;
		b[i][1]=1000;
		b[i][2]=1000;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]-'0'>=0&&a[i][j]-'0'<=9)
			{
				if(j<(m-j))
					b[i][0]=min(b[i][0],j);
				else
					b[i][0]=min(b[i][0],m-j);
			}
			if(a[i][j]>='a'&&a[i][j]<='z')
			{
				if(j<m-j)
					b[i][1]=min(b[i][1],j);
				else
					b[i][1]=min(b[i][1],m-j);
			}
			if(a[i][j]=='*'||a[i][j]=='#'||a[i][j]=='&')
			{
				if(j<m-j)
					b[i][2]=min(b[i][2],j);
				else
					b[i][2]=min(b[i][2],m-j);
			}
		}
	}
int	minxx=1000;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				minxx=min(minxx,b[i][0]+b[j][1]+b[k][2]);
				minxx=min(minxx,b[i][0]+b[j][2]+b[k][1]);
				minxx=min(minxx,b[i][1]+b[j][0]+b[k][2]);
				minxx=min(minxx,b[i][1]+b[j][2]+b[k][0]);
				minxx=min(minxx,b[i][2]+b[j][0]+b[k][1]);
				minxx=min(minxx,b[i][2]+b[j][1]+b[k][0]);
			}
		}
	}
	printf("%d\n",minxx);
	return 0;
}
