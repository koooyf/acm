#include<cstdio>
bool flag=false;
int a[10][10]={0};
void query(int dir){
	if(dir==1){
		for(int j=1;j<=4;j++){
			for(int i=1;i<=4;i++){
				for(int q=1;q<=5;q++){
					if(a[i][j]!=0) break;
					for(int k=i;k<=4;k++) a[k][j]=a[k+1][j];
				}
			}
			for(int i=1;i<=4;i++){
				if(a[i][j]>0&&a[i][j]==a[i+1][j]){
					a[i][j]+=a[i+1][j];
					for(int k=i+1;k<=4;k++) a[k][j]=a[k+1][j];
				}
			}
		}
	}else if(dir==2){
		for(int j=1;j<=4;j++){
			for(int i=4;i>0;i--){
				for(int q=1;q<=5;q++){
					if(a[i][j]!=0) break;
					for(int k=i;k>0;k--) a[k][j]=a[k-1][j];
				}
			}
			for(int i=4;i>0;i--){
				if(a[i][j]>0&&a[i][j]==a[i-1][j]){
					a[i][j]+=a[i-1][j];
					for(int k=i-1;k>0;k--) a[k][j]=a[k-1][j];
				}
			}
		}
	}else if(dir==3){
		for(int j=1;j<=4;j++){
			for(int i=1;i<=4;i++){
				for(int q=1;q<=5;q++){
					if(a[j][i]!=0) break;
					for(int k=i;k<=4;k++) a[j][k]=a[j][k+1];
				}
			}
			for(int i=1;i<=4;i++){
				if(a[j][i]>0&&a[j][i]==a[j][i+1]){
					a[j][i]+=a[j][i+1];
					for(int k=i+1;k<=4;k++) a[j][k]=a[j][k+1];
				}
			}
		}
	}else{
		for(int j=1;j<=4;j++){
			for(int i=4;i>0;i--){
				for(int q=1;q<=5;q++){
					if(a[j][i]!=0) break;
					for(int k=i;k>0;k--) a[j][k]=a[j][k-1];
				}
			}
			for(int i=4;i>0;i--){
				if(a[j][i]>0&&a[j][i]==a[j][i-1]){
					a[j][i]+=a[j][i-1];
					for(int k=i-1;k>0;k--) a[j][k]=a[j][k-1];
				}
			}
		}

	}
}
void output(){
	if(!flag) flag=true; else printf("\n");
	for(int i=1;i<=4;i++){
		for(int j=1;j<4;j++) printf("%5d ",a[i][j]);
		printf("%5d\n",a[i][4]);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=1;i<=4;i++)
			for(int j=1;j<=4;j++)
				scanf("%d",&a[i][j]);
		int q;
		scanf("%d",&q);
		while(q--){
			int dir;
			scanf("%d",&dir);
			query(dir);
			output();
		}
	}
	return 0;
}
