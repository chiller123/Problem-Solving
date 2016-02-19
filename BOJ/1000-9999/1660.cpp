#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 100000000
vector<int> cannon,dp; int n;
// �������� �� ������ �ݾ�, �� ������ ������ �������� ���ٸ� ���� DP�� ���� �����̴�.
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