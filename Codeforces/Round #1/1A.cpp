#include <cstdio>
// ������ ���� ����.
// �־��� Ÿ�Ϸ� �ش� ������ ��ġ�� ä�� �� ������ �ȴ�.
long long n,m,a;
int main(){
	scanf("%lld%lld%lld",&n,&m,&a);
	printf("%lld",(n%a?n/a+1:n/a)*(m%a?m/a+1:m/a));
}