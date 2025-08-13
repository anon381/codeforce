#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>
#include <utility>

#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define vec std::vector
#define pii std::pair<int, int>
#define se second
#define fi first
#define pb push_back
#define maxel(v) *max_element(v.begin(), v.end())
#define minel(v) *min_element(v.begin(), v.end())
#define yes std::cout << "YES\n";
#define m1 std::cout << "-1\n";
#define no std::cout << "NO\n";
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1e9 + 7;

std::map<ll, ll> memo_H;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll get_P(ll k) {
    if (k == 0) return 1;
    ll res = 1;
    for (ll p = 0; p < 60; ++p) {
        ll term = 1LL << p;
        if (term > k) break;
        ll count = (k / term + 1) / 2;
        if (count == 0) continue;
        res = (res * power(p + 1, count)) % mod;
    }
    return res;
}

ll get_H(ll g) {
    if (g <= 1) return 1;
    if (memo_H.count(g)) return memo_H[g];
    ll h_prev = get_H(g - 1);
    ll res = (g - 1) * h_prev % mod * h_prev % mod;
    return memo_H[g] = res;
}

void solve() {
    int n;
    ll k;
    std::cin >> n >> k;
    std::set<ll> s;
    for (int i = 0; i < n; ++i) {
        ll val;
        std::cin >> val;
        s.insert(val);
    }

    ll g = 1;
    while (s.count(g)) {
        g++;
    }

    vec<ll> events;
    events.push_back(g);
    for (ll val : s) {
        if (val >= g) {
            events.push_back(val);
        }
    }

    ll ans = 1;

    for (size_t i = 0; i < events.size(); ++i) {
        if (k == 0) break;
        ll current_g = events[i];

        if (current_g > 1) {
            ll ops_needed = -1;
            if (current_g - 1 < 31) {
                ops_needed = (1LL << (current_g - 1)) - 1;
            }

            if (ops_needed != -1 && k >= ops_needed) {
                k -= ops_needed;
                ans = (ans * get_H(current_g)) % mod;
            } else {
                ans = (ans * get_P(k)) % mod;
                k = 0;
                break;
            }
        }

        if (k == 0) break;

        if (i + 1 < events.size()) {
            k--;
            ans = (ans * events[i + 1]) % mod;
        } else {
            ans = (ans * get_P(k)) % mod;
            k = 0;
        }
    }

    std::cout << ans << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
