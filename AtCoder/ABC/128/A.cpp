#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N, M, c, k, s;
vector<int> v;
vector<vector<int>> switches;
vector<int> cong;
int main() 
{
  freopen("input.txt", "r", stdin);
  scanf("%d%d", &N, &M);
  
  for (int i = 0; i < M; ++i) {
    vector<int> sw; scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      scanf("%d", &s);
      sw.push_back(s);
    }
    switches.emplace_back(sw);
  }

  for (int i = 0; i < M; ++i) {
    scanf("%d", &c);
    cong.push_back(c);
  }
  int ans = 0;
  for (int i = 0; i < (1 << N); ++i) {
    vector<bool> turnOn(N, false);
    int sw = i, j = N-1;
    while (sw) {
      turnOn[j] = sw % 2;
      j--;
      sw >>= 1;
    }

    int bulb_cnt = 0;
    for (int j = 0; j < M; ++j) {
      int cnt = 0;
      for (int & ss : switches[j]) {
        if (turnOn[ss-1]) {
          cnt++;
        }
      }
      if (cnt % 2 == cong[j]) bulb_cnt++;
    }
    if (bulb_cnt == M) ans++;
  }



  printf("%d", ans);
}