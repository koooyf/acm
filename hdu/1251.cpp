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
				return 0;
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
int main()
{
	char s[200];
	memset(tree[0].next,-1,sizeof(tree[0].next));
	while(true)
	{
		gets(s);
		if(s[0]=='\0')
			break;
		insert(s);
	}
	while(scanf("%s",s)!=EOF)
	{
		printf("%d\n",query(s));
	}
	return 0;
}
