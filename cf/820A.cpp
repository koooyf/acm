#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
int main()
{
	int c,v0,v1,a,l,day=1;
	scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l);
	c-=v0;
	while(c>0)
	{
		c+=l;
		v0+=a;
		if(v0>=v1) 
			v0=v1;
		c-=v0;
		day++;
	}
	printf("%d\n",day);
	return 0;
}
