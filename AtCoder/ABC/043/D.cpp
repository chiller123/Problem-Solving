#include <cstdio>
#include <cstring>
char str[100005];

// unbalance한 문자열은 과반수 이상이 같은 char로 되어있다.
// xx, xyx 둘 중 하나는 반드시 나와야한다.
int main() {
  scanf("%s", str);
  int len = strlen(str);
  int s = -1, e = -1;
  for (int i = 0; i < len; ++i) {
    if (str[i] == str[i + 1]) {
      s = i + 1;
      e = s + 1;
    } else if (str[i] == str[i + 2]) {
      s = i + 1;
      e = s + 2;
    }
    if (s > 0) break;
  }

  printf("%d %d", s, e);
}