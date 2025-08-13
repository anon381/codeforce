#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin >> t)) return 0;
    while(t--){
        int n; cin >> n;
        vector<unsigned int> a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        if(a[n-1] != b[n-1]) { cout << "NO\n"; continue; }

        vector<unsigned int> d(n-1);
        for(int i=0;i<n-1;i++) d[i] = a[i] ^ b[i];
        bool ok = true;
        for(int i=0;i<n-1 && ok; ){
            if(d[i]==0){ ++i; continue; }
            int j=i;
            while(true){
                if(d[j] == a[j+1]){ i = j+1; break; }
                if(j == n-2){ ok = false; break; }
                if(d[j+1] != (d[j] ^ a[j+1])){ ok = false; break; }
                ++j;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
