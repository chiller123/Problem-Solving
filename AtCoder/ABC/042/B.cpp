#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
  int N,L;
  string str;
  vector<string> v;
  cin >> N >> L;
  for(int i=0; i<N; ++i) {
  	cin >> str;
    v.push_back(str);
  }
  sort(v.begin(), v.end());
  for(string & s: v) cout << s;
}