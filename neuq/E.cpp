#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,q,a[100005],b[100005],maxn[100005][25];
void RMQ(int m)
{
	memset(maxn,0,sizeof(maxn));
	for(int i=1;i<=n;i++)
		maxn[i][0]=b[i];
	for(int j=1;j<25;j++)
	{
		for(int i=1;i<=m;i++)
			if(i+(1<<j)-1<=m)
			{
				maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
			}
	}
}
int getmax(int x, int y)
{
	if(y>=x)
	{
	int k=log(y-x+1.0)/log(2.0);
	return max(maxn[x][k],maxn[y+1-(1<<k)][k]);
	}
	else
		return 0;
}
int main()
{
	while(true)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&q);
		int lll[100005],rrr[100005];
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);		
			m=1;
			b[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])
			{
				b[m]++;	
			}
			else
			{
				m++;
				b[m]=1;
			}
		}
		lll[1]=1,rrr[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])
			{
				lll[i]=lll[i-1];
				rrr[i]=rrr[i-1]+1;
			}
			else
			{
				lll[i]=i;
				rrr[i]=i;
			}		
		}
		for(int i=n-1;i>=1;i--)
		{
			if(a[i]==a[i+1])
			{
				rrr[i]=rrr[i+1];
			}
		}
/*		for(int i=1;i<=n;i++)
		{
			printf("%d %d\n",lll[i],rrr[i]);
		}*/		
		RMQ(m);
		for(int i=1;i<=q;i++)
		{
			int max1,max2,max3,maxsum;
			int l,r,ll=0,rr,j,k;
			scanf("%d %d",&l,&r);
			if(rrr[l]>r)
				printf("%d\n",r-l+1);
			else if(l>lll[r])
				printf("%d\n",r-l+1);
			else if(rrr[l]<=lll[r])
			{
				max1=rrr[l]-l+1;
				max2=r-lll[r]+1;
				int tot=0;
				for(j=1;j<=m;j++)
				{
					tot+=b[j];
					if(tot>=rrr[l])
					break;	
				}
				tot=0;
				for(k=1;k<=m;k++)
				{
					tot+=b[j];
					if(tot>=lll[r])
					break;
				}
				max3=getmax(j+1,k-1);
				maxsum=max(max1,max2);
				maxsum=max(maxsum,max3);
				printf("%d\n",maxsum);
			}
			else
				printf("%d\n",rrr[l]-l+1);			
		}
	}		
	return 0;
}
