int sg[10005];
bool has[10005];//f[j]是指允许取得数目集合, n为堆的最大数量，k为f[]的长度.
void getsg(int *f,int n,int k)
{
	memset(sg,0,sizeof(sg));
	for(int i=1;i<=n;i++)
	{
		memset(has,0,sizeof(has));
		for(int j=1;j<=k;j++)
		{
			if(i-f[j]>=0)
			 has[sg[i-f[j]]]=1;
		}
		for(int j=0;j<=n;j++)
		{
			if(has[j]==0)
			{
				sg[i]=j;
				break;
			}
		}		
	}	
}