#include <cstdio>
#include <algorithm>
typedef long long ll;
int N, A, num;
ll dp[51][2501] = { 1 }, ans = 0;

int main() {
  freopen("input.txt", "r", stdin);
  scanf("%d%d", &N, &A);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &num);
    for (int j = i; j > 0; --j) {
      for (int k = num; k <= 2500; ++k) {
        dp[j][k] += dp[j - 1][k - num];
      }
    }
  }
  for (int i = 1; i <= N; ++i) 
    ans += dp[i][A * i];

  printf("%lld", ans);
}