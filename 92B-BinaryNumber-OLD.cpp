// Counts the steps to reduce a binary number to 1 using specific rules.
// Time Complexity: O(n^2)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Read the binary string
    string s;
    cin >> s;
    int cnt = 0;
    // Repeat until the string becomes "1"
    while (s != "1")
    {
        // If the last character is '0', remove it
        if (s.back() == '0')
            s.pop_back();
        else
        {
            // Find the rightmost '1' sequence
            int i = s.size() - 1;
            while (i >= 0 && s[i] == '1')
                --i;
            // If all are '1', set to "1" followed by zeros
            if (i < 0)
                s = "1" + string(s.size(), '0');
            else
                // Otherwise, flip the rightmost '0' to '1' and set the rest to '0'
                s[i] = '1', s = s.substr(0, i + 1) + string(s.size() - i - 1, '0');
        }
        // Increment step count
        ++cnt;
    }
    // Output the number of steps
    cout << cnt << endl;
    return 0;
}