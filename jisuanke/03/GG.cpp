#include <stdio.h>
#define MAX 1000
int a[MAX];

int main()
{
	int t, n, i, j;

	a[0] = a[1] = 1, a[2] = 2, a[3] = 5;
	for(i = 3; i <= MAX; i++)
	{
		a[i] = 0; 
		for(j = 0; j < i; j++) 
		{
			if(a[j] > 10007) a[j] = a[j] % 10007;
			if(a[i-j-1] > 10007) a[i-j-1] = a[i-j-1] % 10007;
			if(a[i] > 10007) a[i] = a[i] % 10007;
			a[i] += a[j] * a[i-1-j];
		}
	}
	
	while(scanf("%d", &n)!=EOF)
	{
		printf("%d\n", a[n]%10007);
	}
	return 0;
}
