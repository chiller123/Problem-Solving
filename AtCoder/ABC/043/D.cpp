#include <cstdio>
#include <cstring>
char str[100005];

// unbalance�� ���ڿ��� ���ݼ� �̻��� ���� char�� �Ǿ��ִ�.
// xx, xyx �� �� �ϳ��� �ݵ�� ���;��Ѵ�.
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