#include <cstdio>

int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&a,&b);
	printf("%d",a-b);
}