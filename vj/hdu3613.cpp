#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char s[500005],p[1000005];
int r[1000005];
int maxr,pos,id=0;
void findmax()
{
	int len=strlen(p);
	maxr=0,pos=0;
	memset(r,0,sizeof(r));
	for(int i=0;i<len;i++)
	{
		if(i<maxr)
			r[i]=min(r[2*pos-i],maxr-i);
		else
			r[i]=1;
		while(i-r[i]>=0&&i+r[i]<len&&p[i-r[i]]==p[i+r[i]])
			r[i]++;
		if(r[i]+i-1>maxr)
		{
			maxr=r[i]+i-1;
			pos=i;
		}
	}
}
int cnt[1000005];
int main()
{
	int t,d[30];
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<26;i++)
			scanf("%d",&d[i]);
		scanf("%s",s);
		int len=strlen(s);

		int j=0;
		for(int i=0;i<len;i++)
		{
			p[j++]=s[i];
			p[j++]='#';
		}
		p[j]='\0';
//		printf("%s\n",p);
	    findmax();
//		for(int i=0;i<2*len;i++)
//			printf("%d ",r[i]);
//		printf("\n");
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<2*len;i++)
			if(p[i]>='a'&&p[i]<='z')
				cnt[i]=d[p[i]-'a'];
		for(int i=1;i<2*len;i++)
			cnt[i]+=cnt[i-1];
		int maxx=0;
		for(int i=1;i<2*len-2;i=i+2)
		{
			int sum=0;
			int mid=i/2;
			if(r[mid]+mid==i)
				sum+=cnt[i];
			else
				sum+=0;
			 mid=(i+2*len-1)/2;
			if(r[mid]+mid==2*len)
				sum+=cnt[2*len-1]-cnt[i];
			else
				sum+=0;
//			printf("i=%d maxx=%d\n",i,sum);
			if(maxx<sum)
				maxx=sum;
		}
		printf("%d\n",maxx);
	}
	return 0;
}
