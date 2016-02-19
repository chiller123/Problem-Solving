#include <cstdio>
int ban[1000][5],n,mx=-1,ans;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		for(int j=0;j<5;++j){
			scanf("%d",&ban[i][j]);
		}
	}

	for(int k=0;k<n;++k){
		int tmp=0; bool same[1000]={};
		for(int i=0;i<5;++i){
			for(int j=0;j<n;++j){
				if(k==j) continue;
				if(ban[k][i]==ban[j][i]) same[j]=true;
			}
		}
		for(int i=0;i<n;++i) if(same[i]) tmp++;
		if(mx<tmp) mx=tmp, ans=k+1;
	}
	printf("%d",ans);
}