#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,cost[1001],dp[1001];

// �ؾ ������ �������� O(n^2) DP�� �����Ѵ�.

int sol(int b) {
	if(b<=0) return 0;
	int& ret = dp[b];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=b/i; ++j) {
			ret = max(ret, sol(b-j*i)+cost[i]*j);
		}
	}
	return ret;
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d",cost+i);
	printf("%d",sol(n));
}