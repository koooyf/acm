#include <cstdio>
#include <algorithm>
using namespace std;
long long k[100001],l[100001];
long long add[100001];
int main()
{
    long long n,f,ans;
    scanf("%I64d%I64d",&n,&f);
    for(long long i=0;i<n;i++)
    {
        scanf("%I64d%I64d",&k[i],&l[i]);
        add[i]=min(2*k[i],l[i])-min(k[i],l[i]);
    }
    sort(add,add+n);
    reverse(add,add+n);
    ans=0;
    for(long long i=0;i<n;i++)
        ans+=min(k[i],l[i]);
    for(long long i=0;i<f;i++)
        ans+=add[i];
    printf("%I64d\n",ans);
    return 0;
}
