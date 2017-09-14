#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
char s[205];
int l;
int getpos(bool op)
{
	strncpy(s+l,s,l);//l为s的长度
	int i=0,j=1;
	while(i<l&&j<l)
	{
		int k=0;
		while(k<l&&s[i+k]==s[j+k]) ++k;
		if(k>=l) break;
		if((s[i+k]>s[j+k])^op) i+=k+1;//op=0求最小 op=1求最大
		else
			j+=k+1;
		if(i==j) ++j;
	}
	return min(i,j);
}
int main()
{
	int t;
	char p[205];
	while(scanf("%d",&t)!=EOF)
	{
		set<string>q;
		q.clear();
		while(t--)
		{
			scanf("%s",s);
			l=strlen(s);
			int minn=getpos(0);
			for(int i=0;i<l;i++)
				p[i]=s[i+minn];
			p[l]='\0';
			q.insert(p);
		}
		int ans=q.size();
		printf("%d\n",ans);
	}
	return 0;
}
