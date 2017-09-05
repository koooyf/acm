#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char a[100005],b[100005];
	scanf("%s",a);
	scanf("%s",b);
	int lena=strlen(a);
	int lenb=strlen(b);
	int t=min(lena,lenb);
	int tt=max(lena,lenb);
	int i=0,j=-1;
	for(i=0;i<t;i++)
	{
		if(a[i]!=b[i])
		{
			j=i;
			break;	
		}
	}
	if(tt==t&&j==-1)
		printf("-1\n");
	else
	printf("%d\n",tt);
	return 0;
}
