#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
struct Node{
	int next[30];
	int v;
	vector<int>id;
	void init()
	{
		v=0;
		memset(next,-1,sizeof(next));
		id.clear();	
	}
}tree[1000050];
int tot=0;
void insert(char *s,int id)
{
	int now=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		int tmp=s[i]-'a';
		int next=tree[now].next[tmp];
		tree[now].v++;
		tree[now].id.push_back(id);
		if(next==-1)
		{
			next=++tot;
			tree[next].init();
			tree[now].next[tmp]=next;
		}
		now=next;
	}
	tree[now].v++;
	tree[now].id.push_back(id);
}
int query(char *s)
{
	int len=strlen(s);
	int now=0;
	for(int i=0;i<len;i++)
	{
		int tmp=s[i]-'a';
		if(tree[now].next[tmp]==-1)
			return -1;
		now=tree[now].next[tmp];
	}
	return now;
}
int main()
{
	int t,n,w[1005];
	char s[1005][1005],ss[1005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		tot=0;
		memset(tree[0].next,-1,sizeof(tree[0].next));
		tree[0].v=0;
		tree[0].id.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",ss);
			int len=strlen(ss);
			for(int j=0;j<len;j++)
			{
				s[i][j]=ss[len-1-j];
			}
			s[i][len]='\0';
			insert(s[i],i);
			scanf("%d",&w[i]);
		}
		int q,u,v,k,ans=0;
		scanf("%d",&q);
		while(q--)
		{
			ans=0;
			scanf("%d",&u);
			if(u==1)
			{
				scanf("%d%d",&v,&k);
				w[v]=k;
			}
			else
			{
				scanf("%d",&v);
				int m=query(s[v]);
//				printf("%d\n",tree[m].id.size());
				for(int i=0;i<tree[m].id.size();i++)
				{
					if(w[tree[m].id[i]]<=w[v])
					{
						ans++;
					}
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
