#include <cstdio>
#include <algorithm>
 
int main() {
  int a[3];
  for(int i=0; i<3; ++i) {
    scanf("%d", a+i);
  }
  std::sort(a, a+3);
  printf("%s", a[0]==5&&a[1]==5&&a[2]==7?"YES":"NO");
}