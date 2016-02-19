#include <cstdio>
bool a[2000001];
int n,k;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){scanf("%d",&k);a[k+1000000]=true;}
	for(int i=2000000;i>=0;--i) if(a[i]) printf("%d\n",i-1000000);
}