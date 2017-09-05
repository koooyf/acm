#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
void qsort(int L,int r,int *a,int *b,int *c)
{
	int i,j,x,y;
	i=L;
	j=r;
	x=a[(L+r)>>1];
	y=b[(L+r)>>1];
	do{
		while(a[i]<x||(a[i]==x&&b[i]<y)) i++;
		while(a[j]>x||(a[j]==x&&b[j]>y)) j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			swap(c[i],c[j]);
			i++;
			j--;
		}
	}while(i<=j);
	if(L<j) qsort(L,j,a,b,c);
	if(i<r) qsort(i,r,a,b,c);
}
int ans[105][105]={0},cnt[105][105][15]={0};
int main()
{
	int n,q,c,x[100005],y[100005],x1,y1,x2,y2,t,s[100005],sum=0;
	scanf("%d%d%d",&n,&q,&c);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&x[i],&y[i],&s[i]);
	qsort(1,n,x,y,s);
	for(int i=1;i<=n;i++)
		if(!ans[x[i]][y[i]])
			ans[x[i]][y[i]]=i;
	for(int k=0;k<=c;k++)
	{
		for(int i=1;i<=100;i++)
		{
			for(int j=1;j<=100;j++)
			{
				cnt[i][j][k]=cnt[i-1][j][k]+cnt[i][j-1][k]-cnt[i-1][j-1][k];
				if(ans[i][j])
				{
					for(int tt=ans[i][j];tt<=n&&x[tt]==i&&y[tt]==j;tt++)
						cnt[i][j][k]+=(s[tt]+k)%(c+1);
	
				}
			}
		}
	}
	while(q--)
	{
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		int ss=t%(c+1);
		printf("%d\n",cnt[x2][y2][ss]+cnt[x1-1][y1-1][ss]-cnt[x1-1][y2][ss]-cnt[x2][y1-1][ss]);
	}
	return 0;
}
