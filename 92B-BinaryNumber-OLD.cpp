// Counts the steps to reduce a binary number to 1 using specific rules.
// Time Complexity: O(n^2)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    while (s != "1")
    {
        if (s.back() == '0')
            s.pop_back();
        else
        {
            int i = s.size() - 1;
            while (i >= 0 && s[i] == '1')
                --i;
            if (i < 0)
                s = "1" + string(s.size(), '0');
            else
                s[i] = '1', s = s.substr(0, i + 1) + string(s.size() - i - 1, '0');
        }
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}