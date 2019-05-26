#include <cstdio>
int N,mn=101,mx=-101, ans=1e9;
int arr[101];
int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", arr + i);
    mn = mn > arr[i] ? arr[i] : mn;
    mx = mx < arr[i] ? arr[i] : mx;
  }
  for (int now = mn; now <= mx; ++now) {
    int tmp = 0;
    for (int i = 0; i < N; ++i) {
      tmp += (now - arr[i]) * (now - arr[i]);
    }
    if (tmp < ans) {
      ans = tmp;
    }
  }
  printf("%d", ans);
  return 0;
}