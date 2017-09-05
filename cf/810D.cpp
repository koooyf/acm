#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int n,k;
bool check(int x,int y)
{
	string s;
	if(x<0||y>n) return 0;
	cin>>s;
	cout<<1<<' '<<x<<' '<<y<<endl;
	return s=="TAK";
}
int find(int L,int r)
{
	if(r<L) return -1;
	while(r-L>1)
	{
		int mid=(L+r)>>1;
		if(check(mid,mid+1))
			r=mid;
		else
			L=mid;
	}
	int ans=(check(L,r)?L:r);
	return ans;
}
int main()
{
	cin>>n>>k;
	int x=find(1,n);
	int y=find(1,x-1);
	if(!check(y,x)) int y=find(x+1,n);
	cout<<2<<' '<<x<<' '<<y<<endl;
	return 0;
}
