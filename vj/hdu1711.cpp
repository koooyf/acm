#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int t,n,m,s[1000005],p[10005],nx[10005];
int kmpsearch()
{
	int i=0;
	int j=0;
	while(i<n&&j<m)
	{
		if(j==-1||s[i]==p[j])
			j++,i++;
		else
			j=nx[j];
	}
	if(j==m)
		return i-j+1;
	else
		return -1;
}

void getnext()
{
	int k=-1,j=0;
	nx[0]=-1;
	while(j<m-1)
	{
		if(k==-1||p[k]==p[j])
		{
			j++;
			k++;
			if(p[k]!=p[j])
				nx[j]=k;
			else
				nx[j]=nx[k];
		}
		else
			k=nx[k];
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&s[i]);
		for(int i=0;i<m;i++)
			scanf("%d",&p[i]);
		getnext();
		int ans=kmpsearch();
		printf("%d\n",ans);
	}
	return 0;
}
