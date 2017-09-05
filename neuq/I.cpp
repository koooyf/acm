#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char a[100];
	gets(a);
	if(a[0]=='I'&&a[1]=='s')
		printf("Yes, welcome to NEUQ.\n");
	else if(a[0]=='I'&&a[1]==' ')
		printf("What can I do for you?\n");
	return 0;
}
