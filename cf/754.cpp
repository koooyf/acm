#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char mp[10][10];
int kk=0;
bool flag=0,f;
void dfs1(int i,int j,int k)
{
	if(i>3||i<0||j>3||j<0||flag==1)
		return ;
	if(mp[i][j]=='o')
		return ;
	if(mp[i][j]=='.')
		kk++;
	if(k==3)
	{
		flag=1;
		return ;
	}
	dfs1(i+1,j,k+1);
}
void dfs2(int i,int j,int k)
{
	if(i>3||i<0||j>3||j<0||flag==1)
		return ;
	if(mp[i][j]=='o')
		return ;
	if(mp[i][j]=='.')
		kk++;
	if(k==3)
	{
		flag=1;
		return ;
	}
	dfs2(i,j+1,k+1);
}
void dfs3(int i,int j,int k)
{
	if(i>3||i<0||j>3||j<0||flag==1)
		return ;
	if(mp[i][j]=='o')
		return ;
	if(mp[i][j]=='.')
		kk++;
	if(k==3)
	{
		flag=1;
		return ;
	}
	dfs3(i+1,j+1,k+1);
}
void dfs4(int i,int j, int k)
{
	if(i>3||i<0||j>3||j<0||flag==1)
	return ;
	if(mp[i][j]=='o')
		return ;
	if(mp[i][j]=='.')
		kk++;
	if(k==3)
	{
		flag=1;
		return ;
	}
	dfs4(i+1,j-1,k+1);
}
int main()
{
	
	for(int i=0;i<=3;i++)
			scanf("%s",mp[i]);
	for(int i=0;i<=3;i++)
	{
		if(f==1)
			break;
		for(int j=0;j<=3;j++)
		{
			if(mp[i][j]=='x'||mp[i][j]=='.')
			{
				flag=0,kk=0;
				dfs1(i,j,1);
				if(flag==1&&kk<2)
				{
					printf("YES\n");
					f=1;
					break;			
				}
				flag=0,kk=0;
				dfs2(i,j,1);
				if(flag==1&&kk<2)
				{
					printf("YES\n");
					f=1;
					break;
				}
				flag=0,kk=0;
				dfs3(i,j,1);
				if(flag==1&&kk<2)
				{
					printf("YES\n");
					f=1;
					break;
				}
				flag=0,kk=0;
				dfs4(i,j,1);
				if(flag==1&&kk<2)
				{
					printf("YES\n");
					f=1;
					break;
				}
			}
		}
	}
		if(f==0)
			printf("NO\n");
	
	return 0;
}
