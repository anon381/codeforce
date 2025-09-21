#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

const int MOD = 998244353;
const int LIM = 1'000'000;

int spf[LIM + 1];
int invv[LIM + 1];

int64 mod_pow(int64 a, int e) {
  int64 r = 1 % MOD;
  while (e > 0) {
    if (e & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    e >>= 1;
  }
  return r;
}

void build_spf() {
  for (int i = 2; i <= LIM; ++i) spf[i] = 0;
  vector<int> primes;
  for (int i = 2; i <= LIM; ++i) {
    if (!spf[i]) {
      spf[i] = i;
      primes.push_back(i);
    }
    for (int p : primes) {
      if (1LL * p * i > LIM) break;
      spf[p * i] = p;
      if (p == spf[i]) break;
    }
  }
  spf[1] = 1;
}

vector<pair<int,int>> factorize_int(int n) {
  vector<pair<int,int>> f;
  if (n <= 1) return f;
  while (n > 1) {
    int p = spf[n], c = 0;
    while (n % p == 0) n /= p, ++c;
    f.push_back({p, c});
  }
  return f;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  build_spf();

  invv[1] = 1;
  for (int i = 2; i <= LIM; ++i) {
    invv[i] = int( (1LL * (MOD - MOD / i) * invv[MOD % i]) % MOD );
  }

  int T;
  if (!(cin >> T)) return 0;
  while (T--) {
    int x, y, z;
    cin >> x >> y >> z;

    unordered_map<int,int> cnt; cnt.reserve(32);
    auto fx = factorize_int(x);
    auto fy = factorize_int(y);
    auto fz = factorize_int(z);
    for (auto [p, c] : fx) cnt[p] += c;
    for (auto [p, c] : fy) cnt[p] += c;
    for (auto [p, c] : fz) cnt[p] += c;

    int64 ans = 1;
    vector<int> primes_m; primes_m.reserve(cnt.size());
    for (auto &kv : cnt) {
      int p = kv.first, k = kv.second;
      primes_m.push_back(p);
      ans = ans * (p - 1) % MOD;
      ans = ans * mod_pow(invv[p], k) % MOD;
    }

    unordered_map<int,int> E; E.reserve(64);
    for (int p : primes_m) {
      int t = p - 1;
      auto f = factorize_int(t);
      for (auto [r, e] : f) E[r] += e;
    }

    unordered_set<int> Pset(primes_m.begin(), primes_m.end());
    for (auto &kv : E) {
      int r = kv.first, e = kv.second;
      if (Pset.count(r)) {
        ans = ans * mod_pow(invv[r], e) % MOD;
      } else {
        int64 invr = invv[r];
        int64 invrE = mod_pow(invr, e);
        int64 term = (invr + ( (1 - invr + MOD) % MOD ) * invrE) % MOD;
        ans = ans * term % MOD;
      }
    }

    cout << ans << '\n';
  }

  return 0;
}

