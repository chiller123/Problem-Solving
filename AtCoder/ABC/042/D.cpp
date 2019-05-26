#include <cstdio>

// Fermat's Little Theorem 


typedef long long ll;
const ll MOD = 1e9 + 7;
 
 
ll fac[200001] = { 1 };
ll invfac[200001] = { 1 };
 
ll qpow(ll b, ll e) {
  ll c = 1;
  while (e) {
    if (e & 1LL)
      c = (c * b) % MOD;
    b = (b * b) % MOD;
    e /= 2LL;
  }
  return c;
}
 
ll comb(int n, int k) {
  ll tmp = fac[n] * invfac[k] % MOD;
  return tmp * invfac[n - k] % MOD;
}
 
int main()
{
  int h, w, a, b;
  scanf("%d%d%d%d", &h, &w, &a, &b);
  for (int i = 1; i <= h + w; ++i) {
    fac[i] = (fac[i - 1] * i) % MOD;
    invfac[i] = qpow(fac[i], MOD - 2LL);
  }
 
  ll ans = 0;
  for (int i = 1; i <= h - a; ++i) {
    ans = (ans + ((comb(i - 1 + b - 1, i - 1) * comb(h + w - b - i - 1, h - i)) % MOD)) % MOD;
  }
  printf("%lld", ans);
}