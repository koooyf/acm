#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int x,y;
int jug(int a,int b)
{
	if(abs(a-x)==abs(b-y))
	{
		if(a>x&&b>y)
			return 1;
		else if(a>x&&b<y)
			return 3;
		else if(a<x&&b<y)
			return 5;
		else 
			return 7;
	}
	else if(abs(a-x)==0)
	{
		if(b>y)
			return 0;
		else 
			return 4;
	}
	else if(b-y==0)
	{
		if(a>x)
			return 2;
		else 
			return 6;
	}
	else 
		return -1;
}
int main()
{
	int n,i,dir[10],flag,pos[10];
	char s[10];
	while(scanf("%d",&n)!=EOF)
	{
		flag=0;
		memset(dir,-1,sizeof(dir));
		memset(pos,-1,sizeof(pos));
		scanf("%d %d",&x,&y);
		for(i=0;i<n;i++)
		{
			int a,b,vis;
			scanf("%s",&s[0]);
			scanf("%d%d",&a,&b);
			if(s[0]=='R')
				vis=1;
			else if(s[0]=='B')
				vis=2;
			else 
				vis=3;
			int temp=jug(a,b);
			if(temp==-1)
				continue;
			if(temp%2==1)
			{
				if(dir[temp]==-1||dir[temp]>abs(x-a))
				{
					dir[temp]=abs(x-a);
					pos[temp]=vis;
				}
			}
			else if(temp==0||temp==4)
			{
				if(dir[temp]==-1||dir[temp]>abs(y-b))
				{
					dir[temp]=abs(y-b);
					pos[temp]=vis;
				}
			}
			else 
			{
				if(dir[temp]==-1||dir[temp]>abs(x-a))
				{
					dir[temp]=abs(x-a);
					pos[temp]=vis;
				}
			}
		}	
		for(i=0;i<8;i++)
		{
			if(i%2==1)
			{
				if(pos[i]==2||pos[i]==3)
				{
					flag=1;
					break;
				}
			}
			else if(i==0||i==4)
			{
				if(pos[i]==1||pos[i]==3)
				{
					flag=1;
					break;
				}
			}
			else if(i==2||i==6)
			{
				if(pos[i]==1||pos[i]==3)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}
