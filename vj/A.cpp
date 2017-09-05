#include<cstdio>
#include<set>
using namespace std;
int n;
multiset<int> ans;
void dfs(int sum,int last,int size){
	if(sum==n){
		ans.insert(size);
		return;
	}
	for(int i=last;sum+i<=n;i++){
		dfs(sum+i,i,size+1);
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		ans.clear();
		dfs(0,1,0);
		for(multiset<int>::iterator it=ans.begin();it!=ans.end();it++) printf("%d ",*it);
		printf("\n");
	}
	return 0;
}
