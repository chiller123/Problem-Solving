#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 100000000
vector<int> cannon,dp; int n;
// 대포알의 총 개수를 금액, 각 대포알 단위를 동전으로 본다면 동전 DP와 같은 문제이다.
int main(){
	for(int i=1;i*(i+1)*(i+2)<=1800000;++i) cannon.push_back(i*(i+1)*(i+2)/6);
	scanf("%d",&n); dp.assign(n+1, INF);
	for(int ball : cannon){
		if(ball<=n){
			dp[ball]=1;
			for(int i=ball+1;i<=n;++i) dp[i]=min(dp[i],dp[i-ball]+1);
		}
	}
	printf("%d",dp[n]);
}