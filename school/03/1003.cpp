#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
int f[500005],vis[500005],t,n,k;
struct point
{
	int Next;
	int b;
	int where;
	int value;
}biao[500005];
void makebiao()
{
	biao[1]=(point){2,1,1,f[1]};
	for(int i=2;i<=n-1;i++)
	{
		biao[i]=(point){i+1,i-1,i,f[i]};
	}
	biao[n]=(point){n,n-1,n,f[n]};	
}
void shanchu(int i)
{
	if(biao[i].Next==i)
		biao[biao[i].b].Next=biao[biao[i].b].where;
	else if(biao[i].Next!=i)
		biao[biao[i].b].Next=biao[i].Next;
	if(biao[i].b==i)
		biao[biao[i].Next].b=biao[biao[i].Next].where;
	else if(biao[i].b!=i)
		biao[biao[i].Next].b=biao[i].b;	
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
			vis[f[i]]=i;
		}
		makebiao();
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			int x=vis[i];
			int y=x,ans1[81]={0},ans2[81]={0},m=k,cnt1=0,cnt2=0;
			ans1[0]=x,ans2[0]=x;
			while(m--)
			{
				if(x==biao[x].Next)
					break;
				x=biao[x].Next;
				cnt1++;
				ans1[cnt1]=x;
			}
			 m=k,x=y;
			while(m--)
			{
				if(x==biao[x].b)
					break;
				x=biao[x].b;
				cnt2++;
				ans2[cnt2]=x;
			}
			ans2[cnt2+1]=0;
			ans1[cnt1+1]=n+1;
//			printf("cnt = %d %d\n",cnt2,cnt1);
//			printf("ans = %d %d\n",ans2[cnt2],ans1[cnt1]);
			shanchu(y);
			if(cnt1+cnt2>=k-1)
			{
			long long pp=0;
				if(cnt1==k)
				{
				for(int j=0;j<cnt1;j++)
				{
						pp=abs(ans1[j]-ans1[j+1])*abs(ans2[k-j]-ans2[k-j-1]);
					sum+=pp*i;
				}
				}
				else
				{
					for(int j=0;j<=cnt1;j++)
					{
							pp=abs(ans1[j]-ans1[j+1])*abs(ans2[k-j]-ans2[k-j-1]);
						sum+=pp*i;
//						printf("pp = %lld %d\n",pp,i);	
					}
				}
			}		
		}
		printf("%lld\n",sum);
	}
	return 0;
}
