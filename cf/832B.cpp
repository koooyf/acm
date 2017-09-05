#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char s1[30],s2[100005],s[100005],s3[100005];
	int n;
	bool f=0;
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%d",&n);
	for(int k=1;k<=n;k++)
	{
		bool f=0,ff=0,fff=0,flag=0,gg=0,ggg=0;
		scanf("%s",s);
		int t=strlen(s1);
		int p=strlen(s2);
		int tt=strlen(s);
		int x;
		for(int i=0;i<p;i++)
		{
			if(s2[i]=='*')
			{
				f=1;
				x=i;
			}
		}
		if(f)
		{
			int j=0;
			for(int i=0;i<p;i++)
			{
				if(i!=x)
				{
					s3[j]=s2[i];
					j++;
				}
			}
			s3[j]='\0';
			for(int i=0;i<tt;i++)
			{
				if(s[i]!=s3[i]&&s3[i]!='?')
				{
					ff=1;
					break;
				}
				else if(s3[i]=='?')
				{
					for(int j=0;j<t;j++)
					{
						if(s1[j]==s[i])
						{
							fff=1;
							break;					
						}
					}	
				}
			}
			if(!ff&&fff)
			{
				printf("YES\n");
				continue;
			}
			ff=0,fff=0;
			for(int i=0;i<tt;i++)
			{
				if(s[i]!=s2[i]&&s2[i]!='?'&&s2[i]!='*')
				{
					ff=1;
					break;
				}
				else if(s2[i]=='?')
				{
					for(int j=0;j<t;j++)
					{
						if(s[i]==s1[j])
						{
							fff=1;
							break;
						}
					}
				}
				else if(s2[i]=='*')
				{
					for(int j=0;j<t;j++)
					{
						if(s[i]==s1[j])
						{
							flag=1;
							break;
						}
					}
				}	
			}
			if(p==tt)
			{
			if(!ff&&fff)
				printf("YES\n");
			else if(!ff&&!flag)
				printf("YES\n");
			else
				printf("NO\n");
			}
			else
				printf("NO\n");
			
		}
		else if(f==0)
		{
			for(int i=0;i<tt;i++)
			{
				if(s[i]!=s2[i]&&s2[i]!='?')
				{
					gg=1;
					break;	
				}
				else if(s2[i]=='?')
				{
					for(int j=0;j<t;j++)
					{
						if(s[i]==s1[j])
						{
							ggg=1;
							break;
						}
					}
				}
			}
			if(!gg&&ggg)
				printf("YES\n");
			else
				printf("NO\n");		
		}
	}
	return 0;
}
