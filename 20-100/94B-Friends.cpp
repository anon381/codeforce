// Finds the maximum value in a list of friends' scores.
// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Read the number of friends
    int n(0);
    cin >> n;
    // Read each friend's score
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0;
    // Find the maximum score
    for (int i = 0; i < n; ++i)
        ans = max(ans, a[i]);
    // Output the maximum score
    cout << ans << endl;
    return 0;
}