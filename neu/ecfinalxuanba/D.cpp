#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL M=20161119;
struct query{
	int i,k,no,ans;
};
vector<int> u[100005];
LL v[100005];
int pre[100005],lastvj[100005],lastk[100005],maxv[100005],minv[100005];
query qu[100005];
int max(int a,int b){
	if(a>b) return a;
	return b;
}
int min(int a,int b){
	if(a<b) return a;
	return b;
}
void getV(int k){
	maxv[k]=v[k];
	minv[k]=v[k];
	for(vector<int>::iterator it=u[k].begin();it!=u[k].end();it++){
		if(*it==pre[k]) continue;
		pre[*it]=k;
		v[*it]=v[k]*(*it)%M;
		getV(*it);
		maxv[k]=max(maxv[k],maxv[*it]);
		minv[k]=min(minv[k],minv[*it]);
	}
}
bool compare(query a, query b){
	return a.k>b.k;
}
bool compare2(query a,query b){
	return a.no<b.no;
}
int work(int now,int nowq){
	if(u[now].size()==1){
		lastvj[now]=v[now];
		lastk[now]=qu[nowq].k;
		return abs(lastvj[now]-lastk[now]);
	}else{
		if(lastvj[now]<=qu[nowq].k&&qu[nowq].k<=lastk[now]){
			lastk[now]=qu[nowq].k;
			return abs(lastvj[now]-lastk[now]);
		}
		int minnn=abs(v[now]-qu[nowq].k),minvj=v[now];
		for(vector<int>::iterator it=u[now].begin();it!=u[now].end();it++){
			if(*it==pre[now]) continue;
			if(qu[nowq].k>=maxv[*it]||qu[nowq].k<=minv[*it]){
				if(min(abs(qu[nowq].k-maxv[*it]),abs(qu[nowq].k-minv[*it]))>=minnn) continue;
				if(qu[nowq].k>=maxv[*it]){
					minnn=abs(qu[nowq].k-maxv[*it]);
					minvj=maxv[*it];
					lastvj[*it]=maxv[*it];
					lastk[*it]=qu[nowq].k;
					continue;
				}else if(qu[nowq].k<=minv[*it]){
					minnn=abs(qu[nowq].k-minv[*it]);
					minvj=minv[*it];
					lastvj[*it]=minv[*it];
					lastk[*it]=qu[nowq].k;
					continue;
				}
			}
			int tmp=work(*it,nowq);
			if(tmp<minnn){
				minnn=tmp;
				minvj=lastvj[*it];
			}
		}
		lastvj[now]=minvj;
		lastk[now]=qu[nowq].k;
		return minnn;
	}
}
int main()
{
	v[1]=1;
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++) u[i].clear();
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			u[a].push_back(b);
			u[b].push_back(a);
		}
		memset(pre,0,sizeof(pre));
		getV(1);
		int q;
		scanf("%d",&q);
		for(int i=1;i<=q;i++){
			scanf("%d%d",&qu[i].i,&qu[i].k);
			qu[i].no=i;
		}
		sort(qu+1,qu+q+1,compare);
		memset(lastvj,0,sizeof(lastvj));
		memset(lastk,0,sizeof(lastk));
		for(int i=1;i<=q;i++){
			qu[i].ans=work(qu[i].i,i);
		}
		sort(qu+1,qu+q+1,compare2);
		for(int i=1;i<=q;i++) printf("%d\n",qu[i].ans);
	}
	return 0;
}
