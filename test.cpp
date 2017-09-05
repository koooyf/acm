#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
const int N = 5e5+5;
int n;
struct Trie
{
	int next[N][26],fail[N],end[N];
	int root,L;
	int newnode()
	{
		for(int i=0;i<26;i++) next[L][i]=-1;
		end[L++] = 0;
		return L-1;
	}
	void init()
	{
		L=0;
		root = newnode();
	}
	void insert(char *s)
	{
		int len=strlen(s);
		int u=root;
		for(int i=0;i<len;i++)
		{
			int tmp=s[i]-'a';
			if(next[u][tmp]==-1)
				next[u][tmp]=newnode();
			u=next[u][tmp];
		}
		end[u]++;
	}
	void getfail()
	{
		queue<int>q
		fail[root]=root;
		for(int i=0;i<26;i++)
			if(next[root][i]==-1)
				next[root][i]=root;
			else
			{
				fail[next[root][i]] = root;
				q.push(next[root][i]);
			}
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int i=0;i<26;i++)
			{
				if(next[u][i]==-1)
					next[u][i]==next[fail[u]][i];
				else
				{
					fail[next[u][i]]=next[fail[u]][i];
					q.push(next[u][i]);
				}
			}
		}
	}
	int query(*s)
	{
		int len=strlen(a);
		int u=root;
		int res=0;
		for(int i=0;i<len;i++)
		{
			int v=s[i]-'a';
			u=next[u][v];
			int tmp=u;
			while(tmp!=root)
			{
				res+=end[tmp];
				end[tmp]=0;
				tmp=fail[tmp];
			}
		}
		return res;
	}
};
int main()
{

	return 0;
}
