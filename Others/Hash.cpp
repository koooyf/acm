#include<cstdio>
const int hash_seed[]={0,131,1331};
int hash(char *s,int index){
	int ans=0;
	for(int i=0;s[i]!='\0';i++) ans=ans*hash_seed[index]+s[i];
	return ans;
}
int main(){
	char s[100005];
	while(scanf("%s",s)!=EOF){
		printf("%d %d\n",hash(s,1),hash(s,2));
	}
	return 0;
}
