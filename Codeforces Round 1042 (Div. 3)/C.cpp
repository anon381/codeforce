#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec vector
#define pii pair<int, int>
#define se second
#define fi first
#define pb push_back
#define maxel(v) *max_element(v.begin(), v.end())
#define minel(v) *min_element(v.begin(), v.end())
#define yes cout << "YES\n";
#define m1 cout << "-1\n";
#define no cout << "NO\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll mod3 = 998244353;
const double pi = 3.141592653589793238;
const long double EPS = 1e-9;
const int MAXN = 1e5 * 5;
const int LOGN = __lg(MAXN) + 1;

template<typename T>
void printa(const vec<T>& a) {
  for (auto& p: a) {
    cout << p << ' ';
  }
  cout << endl;
}
template<typename T1, typename T2>
istream& operator >> (istream& in, pair<T1, T2>& p){
  in >> p.first;
  in >> p.second;
  return in;
}

template<typename T>
istream& operator >> (istream& in, vector<T>& v){
  for (auto& e : v) in >> e;
  return in;
}
template <typename T>
void print2d(const vec<vec<T>> &vec) {
  for (const auto &row : vec) {
    for (const auto &i : row) {
      cout << i << " ";
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  if (!(cin >> tt)) return 0;
  while (tt--) {
    int n;
    ll k;
    cin >> n >> k;
    vec<ll> s(n), t(n);
    cin >> s;
    cin >> t;
    if (k == 0) {
      sort(all(s));
      sort(all(t));
      if (s == t) yes else no
      continue;
    }
    unordered_map<ll,int> cnt;
    cnt.reserve(n*2);
    for (auto &x : s) {
      ll r = x % k;
      if (r < 0) r += k;
      ll nr = min(r, k - r);
      cnt[nr]++;
    }
    for (auto &x : t) {
      ll r = x % k;
      if (r < 0) r += k;
      ll nr = min(r, k - r);
      cnt[nr]--;
    }
    bool ok = true;
    for (auto &p : cnt) if (p.second != 0) { ok = false; break; }
    if (ok) yes else no
  }
  return 0;
}
