#include <cstdio>
using namespace std;
int N, K, num;
int k[10];
 
int main()
{
  scanf("%d%d", &N, &K);
  for (int i = 0; i < K; ++i) {
    scanf("%d", &num);
    k[num] = 1;
  }
  for (int ans = N; ans <= N * 10; ++ans) {
    int now = ans;
    bool isCorrect = true;
    while (now) {
      int ones = now % 10;
      if (k[ones]) {
        isCorrect = false;
      }
      now /= 10;
    }
    if (isCorrect) {
      printf("%d", ans);
      break;
    }
  }
}