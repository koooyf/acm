#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
struct node{
	int next[30];
	int v;
	void init(){
		v=0;
		memset(next,-1,sizeof(next));
	}
}tree[2000000];
int tot=0;
void insert(char *s)
{
	int now=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		int tmp=s[i]-'a';
		int next=tree[now].next[tmp];
		tree[now].v++;
		if(next==-1)
		{
			next=++tot;
			tree[next].init();
			tree[now].next[tmp]=next;
		} 
		now=next;
	}
	tree[now].v++;
}
int query(char *s)
{
	int len=strlen(s);
	int now=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			int tmp=s[i]-'a';
			if(tree[now].next[tmp]==-1)
				return -1;
			now=tree[now].next[tmp];
		}
		else if(s[i]=='#')
		{
			for(int j=0;j<26;j++)
			{
				
			}
		}
	}
	return tree[now].v;
}
int t,n,q,ss[500005],p[500005],w[500005],ww[2000000],sp[500005];
void init1()
{
	int len=strlen(w);
	int ans=0;
	for(int i=0;i<len;i++)
	{
		ww[ans]=w[i];
		ans++;
		ww[ans]=w[n-i-1];
		ans++;
	}
}
void init()
{
	int len1=str(ss);
	int len2=str(p);
	int ans=0;
	if(len1>len2)
	{
		for(int i=len2;i<len1;i++)
		{
			p[i]='#';
		}
		p[len1]='\0';
	}
	else
	{
		for(int i=len1;i<len2;i++)
			ss[i]='#';
		ss[len2]='\0';
	}
	for(int i=0;i<max(len1,len2);i++)
	{
		sp[ans]=ss[i];
		ans++;
		sp[ans]=p[max(len1,len2)-1-i];
		ans++;
	}
}
using namespace std;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
				
	}
	return 0;
}
