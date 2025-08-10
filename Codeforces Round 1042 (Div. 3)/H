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
void printa(const vec<T> a) {
    for (auto& p: a) cout << p << ' ';
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
void print2d(const vec<vec<T>> &v) {
    for (const auto &row : v) {
        for (const auto &i : row) cout << i << " ";
        cout << endl;
    }
}
 
const int LIM = 1000000 + 5;
int spf[LIM];
int mu[LIM];
bool sieve_done = false;
 
void init_sieve() {
    if (sieve_done) return;
    vec<int> pr;
    mu[1] = 1;
    for (int i = 2; i < LIM; ++i) {
        if (!spf[i]) spf[i] = i, pr.pb(i), mu[i] = -1;
        for (int p: pr) {
            ll x = 1LL * p * i;
            if (x >= LIM) break;
            spf[x] = p;
            if (p == spf[i]) { mu[x] = 0; break; }
            else mu[x] = -mu[i];
        }
    }
    sieve_done = true;
}
 
inline vec<int> getpf(int x){
    vec<int> r;
    while (x > 1){
        int p = spf[x];
        r.pb(p);
        while (x % p == 0) x /= p;
    }
    return r;
}
 
inline vec<int> getsqd(const vec<int>& pf){
    vec<int> d = {1};
    for (int p: pf){
        int sz = (int)d.size();
        for (int i = 0; i < sz; ++i) d.pb(d[i] * p);
    }
    return d;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init_sieve();
 
    int t; 
    if(!(cin >> t)) return 0;
    while (t--){
        int n, m; 
        cin >> n >> m;
        vec<int> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
 
        vec<int> cnt(m+1, 0);
        for (int i = 1; i <= n; ++i) ++cnt[a[i]];
 
        vec<int> g(m+1, 0);
        for (int d = 1; d <= m; ++d){
            for (int k = d; k <= m; k += d) g[d] += cnt[k];
        }
 
        unordered_map<int,int> id;
        id.reserve(n*2);
        vec<int> vals;
        vec<vec<int>> pos;
        for (int i = 1; i <= n; ++i){
            int x = a[i];
            auto it = id.find(x);
            if (it == id.end()){
                int idx = (int)vals.size();
                id[x] = idx;
                vals.pb(x);
                pos.pb(vec<int>());
                pos[idx].pb(i);
            }else pos[it->se].pb(i);
        }
 
        int U = (int)vals.size();
        vec<vec<int>> pfv(U), sqdv(U);
        for (int z = 0; z < U; ++z){
            if (vals[z] == 1){ pfv[z] = {}; sqdv[z] = {1}; }
            else{
                pfv[z] = getpf(vals[z]);
                sqdv[z] = getsqd(pfv[z]);
            }
        }
 
        auto F = [&](int z, vec<int>& gg)->int{
            int s = 0;
            for (int d: sqdv[z]) s += mu[d] * gg[d];
            return s;
        };
 
        vec<int> ones;
        if (id.count(1)){
            int z = id[1];
            for (int idx: pos[z]) ones.pb(idx);
        }
        
 
        if ((int)ones.size() >= 4){
            cout << ones[0] << " " << ones[1] << " " << ones[2] << " " << ones[3] << endl;
            continue;
        }
        if ((int)ones.size() == 3){
            int x = -1;
            for (int i = 1; i <= n; ++i){
                if (i!=ones[0] && i!=ones[1] && i!=ones[2]) { x = i; break; }
            }
            if (x==-1){ cout << 0 << endl; continue; }
            cout << ones[0] << " " << ones[1] << " " << ones[2] << " " << x << endl;
            continue;
        }
        if ((int)ones.size() == 2){
            int x = -1, y = -1;
            for (int i = 1; i <= n; ++i){
                if (i==ones[0] || i==ones[1]) continue;
                if (x==-1) x = i;
                else { y = i; break; }
            }
            if (y==-1){ cout << 0 << endl; continue; }
            cout << ones[0] << " " << x << " " << ones[1] << " " << y << endl;
            continue;
        }
 
        bool done = false;
 
        for (int z = 0; z < U && !done; ++z){
            if (vals[z] == 1) continue;
            if ((int)pos[z].size() >= 2){
                int cop = F(z, g);
                if (cop >= 2){
                    int v = vals[z];
                    int j = -1, k = -1;
                    for (int i = 1; i <= n && (k==-1); ++i){
                        if (std::gcd(v, a[i]) == 1){
                            if (j==-1) j = i;
                            else k = i;
                        }
                    }
                    if (j!=-1 && k!=-1){
                        cout << pos[z][0] << " " << j << " " << pos[z][1] << " " << k << endl;
                        done = true;
                    }
                }
            }
        }
        if (done) continue;
 
        if ((int)ones.size() == 1){
            int o = ones[0];
            bool ok = false;
            for (int z = 0; z < U && !ok; ++z){
                if (vals[z] == 1) continue;
                int cop_no1 = F(z, g) - 1;
                if (cop_no1 >= 1){
                    int i_idx = pos[z][0];
                    int j_idx = -1;
                    for (int t = 1; t <= n; ++t){
                        if (t==o || t==i_idx) continue;
                        if (std::gcd(vals[z], a[t]) == 1){ j_idx = t; break; }
                    }
                    if (j_idx == -1) continue;
                    int k_idx = -1;
                    for (int t = 1; t <= n; ++t){
                        if (t==o || t==i_idx || t==j_idx) continue;
                        k_idx = t; break;
                    }
                    if (k_idx == -1){ cout << 0 << endl; ok = true; break; }
                    cout << i_idx << " " << j_idx << " " << o << " " << k_idx << endl;
                    ok = true;
                }
            }
            if (!ok) cout << 0 << endl;
            continue;
        }
 
        vec<int> deg_val(U, 0);
        for (int z = 0; z < U; ++z){
            int fz = F(z, g);
            if (vals[z] == 1) fz -= 1;
            deg_val[z] = fz;
        }
 
        vec<int> used(n+1, 0);
 
        auto remove_idx = [&](int idx, int dlt){
            int z = id[a[idx]];
            for (int d: sqdv[z]) g[d] += dlt;
        };
 
        auto find_second = [&](int ban1, int ban2)->pii{
            for (int r = 1; r <= n; ++r){
                if (r==ban1 || r==ban2) continue;
                int zr = id[a[r]];
                int can = 0;
                int s = 0;
                for (int d: sqdv[zr]) s += mu[d] * g[d];
                if (a[r]==1) s -= 1;
                if (s >= 1){
                    for (int t = 1; t <= n; ++t){
                        if (t==ban1 || t==ban2 || t==r) continue;
                        if (std::gcd(a[r], a[t]) == 1){ can = t; break; }
                    }
                    if (can){ return {r, can}; }
                }
            }
            return {-1,-1};
        };
 
 
 
        int leaf_i = -1, leaf_j = -1;
        for (int z = 0; z < U; ++z){
            if (deg_val[z] == 1){
                int ii = pos[z][0];
                int jj = -1;
                for (int t = 1; t <= n; ++t){
                    if (t==ii) continue;
                    if (std::gcd(a[ii], a[t]) == 1){ jj = t; break; }
                }
                if (jj != -1){ leaf_i = ii; leaf_j = jj; break; }
            }
        }
        if (leaf_i != -1){
            remove_idx(leaf_i, -1);
            remove_idx(leaf_j, -1);
            auto pr = find_second(leaf_i, leaf_j);
            if (pr.fi != -1){
                cout << leaf_i << " " << leaf_j << " " << pr.fi << " " << pr.se << endl;
                done = true;
            }else{
                remove_idx(leaf_i, +1);
                remove_idx(leaf_j, +1);
                cout << 0 << endl;
                continue;
            }
        }
        if (done) continue;
 
        vec<int> order_idx;
        order_idx.reserve(n);
        for (int z = 0; z < U; ++z){
            if (deg_val[z] >= 1){
                for (int idx: pos[z]) order_idx.pb(idx);
            }
        }
        sort(all(order_idx), [&](int i, int j){
            int zi = id[a[i]], zj = id[a[j]];
            if (deg_val[zi] != deg_val[zj]) return deg_val[zi] < deg_val[zj];
            return i < j;
        });
 
        bool found = false;
        for (int ii : order_idx){
            if (found) break;
            int take = min(30, n-1);
            vec<int> cand;
            cand.reserve(take);
            for (int t = 1; t <= n && (int)cand.size() < take; ++t){
                if (t==ii) continue;
                if (std::gcd(a[ii], a[t]) == 1) cand.pb(t);
            }
            for (int jj : cand){
                remove_idx(ii, -1);
                remove_idx(jj, -1);
                auto pr = find_second(ii, jj);
                if (pr.fi != -1){
                    cout << ii << " " << jj << " " << pr.fi << " " << pr.se << endl;
                    found = true;
                    break;
                }
                remove_idx(ii, +1);
                remove_idx(jj, +1);
            }
        }
        if (!found) cout << 0 << endl;
    }
    return 0;
}
