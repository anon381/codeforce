// Finds the maximum value in a list of friends' scores.
// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n(0);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, a[i]);
    cout << ans << endl;
    return 0;
}