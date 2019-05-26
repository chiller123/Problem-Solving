#include <cstdio>
char s[11], r[11];
int idx = -1;
int main()
{
  scanf("%s", s);
  for (int i = 0; s[i]; ++i) {
    switch (s[i]) {
    case '0':
      r[++idx] = '0';
      break;
    case '1':
      r[++idx] = '1';
      break;
    case 'B':
      idx = idx - 1 >= -1 ? idx - 1 : -1;
      break;
    }

  }
  r[idx + 1] = NULL;
  puts(r);
  return 0;
}