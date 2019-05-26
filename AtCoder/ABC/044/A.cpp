#include <cstdio>
#include <algorithm>
int main() {
  int N, K, X, Y;
  scanf("%d%d%d%d", &N, &K, &X, &Y);
  printf("%d", std::min(N, K) * X + std::max(N - K, 0) * Y);
}