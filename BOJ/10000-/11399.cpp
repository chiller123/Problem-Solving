#include <cstdio>
#include <algorithm>

int a[1001],psum[1001],n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) psum[i]=psum[i-1]+a[i], ans+=psum[i];
	printf("%d",ans);
}