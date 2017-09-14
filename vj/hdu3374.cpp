#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
char s[2000005];
int nx[2000005];
int l;
void getnext()
{
	int sLen=strlen(s);
	    nx[0]=-1;
		int k=-1,j=0;
	while(j<sLen)
	{
		if(k==-1||s[k]==s[j])
		{
			k++,j++;
			nx[j]=k;
		}
		else
			k=nx[k];
	}
}
int getpos(bool op)
{
//	int l=strlen(s);
	strncpy(s+l,s,l);
	int i=0,j=1;
	while(i<l&&j<l)
	{
		int k=0;
		while(k<l&&s[i+k]==s[j+k]) ++k;
		if(k>=l) break;
		if((s[i+k]>s[j+k])^op) i+=k+1;
		else
			j+=k+1;
		if(i==j) ++j;
	}
	return min(i,j);
}
int main()
{
	while(scanf("%s",s)!=EOF)
	{
		int len=strlen(s);
		int ans;
		l=len;
		getnext();
		if(len%(len-nx[len])==0)
			ans=len/(len-nx[len]);
		else
			ans=1;
		int minn=getpos(0)+1;
		int maxx=getpos(1)+1;
		printf("%d %d %d %d\n",minn,ans,maxx,ans);
	}
	return 0;
}
