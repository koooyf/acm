#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	int t;
	char c,mp[3][3],mmp[3][3];
	scanf("%d",&t);
	while(t--)
	{
		int x[20],y[20];
		int cnt=0;
		getchar();
		scanf("%c",&c);
		for(int i=0;i<3;i++)
			scanf("%s",mp[i]);
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				mmp[i][j]=mp[i][j];
				if(mp[i][j]=='.')
				{
					cnt++;
					x[cnt]=i,y[cnt]=j;
				}					
			}
		}
		if(cnt>=3)
		{
			for(int i=1;i<=cnt;i++)
			{
				for(int j=1;j<=cnt;j++)
				{
					for(int k=1;k<=cnt;k++)
					{
						if(i!=j&&i!=k&&j!=k)
						{
							mmp[x[i]][y[i]]=c;
							if(mmp[0][0]==mp[1][1]&&mp[0][0]==mp[2][2]&&mp[0][0]==c)
								f=1;
							else(mmp[0][0]==mmp[1][0]&&mmp[1])
						}
					}
				}
			}
		}
	}
	return 0;
}
