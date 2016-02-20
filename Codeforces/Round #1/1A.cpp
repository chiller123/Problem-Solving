#include <cstdio>
// 간단한 수학 문제.
// 주어진 타일로 해당 면적을 넘치게 채울 수 있으면 된다.
long long n,m,a;
int main(){
	scanf("%lld%lld%lld",&n,&m,&a);
	printf("%lld",(n%a?n/a+1:n/a)*(m%a?m/a+1:m/a));
}