#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int t,n;
char a[2000];
char tree[8000];
void build(int node,int begin,int end)
{
	if(end==begin)
	{
		if(a[end]=='1')
			tree[node]='I';
		else if(a[end]=='0')
			tree[node]='B';
	}
	else
	{
		int m=(begin+end)/2;
		build(2*node,begin,m);
		build(2*node+1,m+1,end);
		if(tree[2*node]=='I'&&tree[2*node]==tree[2*node+1])
			tree[node]='I';
		else if(tree[2*node]=='B'&&tree[2*node]==tree[2*node+1])
			tree[node]='B';
		else if(tree[2*node]=='F'||tree[2*node+1]=='F')
			tree[node]='F';
		else if(tree[2*node]!=tree[2*node+1])
			tree[node]='F';
	}
	printf("%c",tree[node]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",a);
		memset(tree,0,sizeof(tree));
		int n=strlen(a);
		build(1,0,n-1);
		printf("\n");
	}
	return 0;
}
