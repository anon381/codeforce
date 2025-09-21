#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        int n; 
        cin >> n;
        unordered_map<long long, long long> freq;
        freq.reserve((size_t)n * 2);
        for (int i = 0; i < n; ++i) {
            long long x; cin >> x;
            ++freq[x];
        }
        vector<pair<long long,long long>> groups;
        groups.reserve(freq.size());
        for (auto &p : freq) groups.push_back({p.second, p.first});
        sort(groups.begin(), groups.end(), [](const auto& A, const auto& B){
            if (A.first != B.first) return A.first > B.first;
            return A.second > B.second;
        });
        
        long long A = 0, B = 0;
        int turn = 0;
        for (auto &g : groups) {
            long long c = g.first;
            long long L = g.second;
            long long alice_moves = (L + (turn == 0)) / 2;
            long long bob_moves   = L - alice_moves;
            A += alice_moves * c;
            B += bob_moves   * c;
            if (L & 1) turn ^= 1;
        }
        cout << A << ' ' << B << "\n";
    }
    return 0;
}

