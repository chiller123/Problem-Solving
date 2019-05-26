#include <cstdio>
int occur[26];
char s[101];
int main() {
  scanf("%s", s);
  for (int i = 0; s[i]; ++i) {
    occur[s[i] - 'a']++;
  }

  for (int i = 0; i < 26; ++i) {
    if (occur[i] & 1) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
}