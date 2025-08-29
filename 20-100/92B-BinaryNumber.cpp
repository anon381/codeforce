// Counts the steps to reduce a binary number to 1 using specific rules.
// Time Complexity: O(n^2)
// Space Complexity: O(n)
#include <cstdio>
#include <iostream>
#include <string>

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Read the binary string
    std::string s;
    std::cin >> s;
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
                s = "1" + std::string(s.size(), '0');
            else
                // Otherwise, flip the rightmost '0' to '1' and set the rest to '0'
                s[i] = '1', s = s.substr(0, i + 1) + std::string(s.size() - i - 1, '0');
        }
        // Increment step count
        ++cnt;
    }
    // Output the number of steps
    std::cout << cnt << std::endl;
    return 0;
}

int main(){

    std::string inputString("1");
    getline(std::cin, inputString);

    bool middleState(0);
    long counter(0);

    // Iterate over the string in reverse
    for(int k = inputString.size() - 1; k >= 0; k--){
        // If not in middle of '1's and current char is '0', increment counter
        if(!middleState && inputString[k] == '0'){++counter;}
        // If in middle of '1's and current char is '0', increment counter by 2
        else if(middleState && inputString[k] == '0'){counter += 2;}
        // If current char is '1' and not the first char, increment counter and change state
        else if(inputString[k] == '1' && k > 0){++counter; middleState = 1;}
        // If current char is '1' and already in middle state, increment counter by 2
        else if(inputString[k] == '1' && middleState == 1){counter += 2;}
    }

    printf("%ld\n", counter);

    return 0;
}