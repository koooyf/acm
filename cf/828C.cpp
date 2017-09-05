#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char s[3000050],t[3000050];
int vis[3000500];
int find(int a)
{
	int r=a;
	while(vis[r]!=r)
	r=vis[r];
	int i=a;
	int j;
//	printf("b=%d %d\n",a,r);
	while(i!=r)
	{
		j=vis[i];
		vis[i]=r;
		i=j;
	}
	return r;	
}
void merge(int a,int b)
{
	int aa=find(a);
	int bb=find(b);
	if(aa>bb)
		vis[bb]=aa;
	else
		vis[aa]=bb;
	return ;
}
int main()
{
	int n,k,x,maxx=-1;
	scanf("%d",&n);
	for(int i=0;i<3000500;i++)
		vis[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",t);
		int tt=strlen(t);
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			int tmpx=x;
/*			for(int r=vis[x];r<=tt+x-1;r=vis[r])
			{
				s[r]=t[r-x];
				vis[r]=vis[r+1];
			}
			for(int r=vis[x];r<=tt+x-1;r=vis[r])
			{
				vis[r]=vis[tt+x-1];
			}*/
			while(x<=tt+tmpx-1)
			{
//				printf("%d\n",x);
				s[x]=t[x-tmpx];
				x=find(x);
		//		printf("%d\n",x);
				if(x<=tmpx+tt-1) merge(x,x+1);
			}
			if(maxx<tt+tmpx-1)
				maxx=tt+tmpx-1;
		}
	}
	for(int i=1;i<=maxx;i++)
	{
		if(s[i]=='\0')
			s[i]='a';
		printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}
