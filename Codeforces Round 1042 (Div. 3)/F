#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
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
const ll mod2 = 1e9 + 9;
const ll mod3 = 998244353;
const double pi = 3.141592653589793238;
const long double EPS = 1e-9;
const int MAXN = 1e5 * 5;

template<typename T>
void printa(const vec<T>& a) {
    for (const auto& p : a) {
        std::cout << p << ' ';
    }
    std::cout << endl;
}
template<typename T1, typename T2>
std::istream& operator >> (std::istream& in, std::pair<T1, T2>& p){
    in >> p.first;
    in >> p.second;
    return in;
}

template<typename T>
std::istream& operator >> (std::istream& in, vec<T>& v){
    for (auto& e : v) in >> e;
    return in;
}

template <typename T>
void print2d(const vec<vec<T>>& v) { 
    for (const auto& row : v) {     
        for (const auto& i : row) {
            std::cout << i << " ";
        }
        std::cout << endl;
    }
}

void solve() {
    ll n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;

    vec<ll> pa(n + 1, 0);
    vec<ll> pb(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pa[i + 1] = pa[i] + (a[i] - '0');
        pb[i + 1] = pb[i] + (b[i] - '0');
    }

    vec<ll> va(n);
    vec<ll> vb(n);
    for (int i = 0; i < n; ++i) {
        va[i] = 2 * pa[i + 1] - (i + 1);
        vb[i] = 2 * pb[i + 1] - (i + 1);
    }

    sort(all(vb));

    vec<ll> p_sum_vb(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        p_sum_vb[i + 1] = p_sum_vb[i] + vb[i];
    }
    ll tot_sum_vb = p_sum_vb[n];

    ll abs_sum = 0;
    for (ll c : va) {
        ll k = std::lower_bound(all(vb), -c) - vb.begin();
        abs_sum += c * (n - 2 * k) + tot_sum_vb - 2 * p_sum_vb[k];
    }

    ll tot_xy_sum = n * n * (n + 1);
    ll ans = (tot_xy_sum - abs_sum) / 2;
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
