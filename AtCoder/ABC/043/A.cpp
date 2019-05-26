#include <cstdio>

int main() {
  freopen("input.txt", "r", stdin);
  int N; scanf("%d", &N);
  printf("%d", N * (N + 1) / 2);
  return 0;
}