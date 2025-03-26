// Time Complexity: O(n^2)
// Space Complexity: O(n)
#include <cstdio>
#include <iostream>
#include <string>

#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::string s;
    std::cin >> s;
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
                s = "1" + std::string(s.size(), '0');
            else
                s[i] = '1', s = s.substr(0, i + 1) + std::string(s.size() - i - 1, '0');
        }
        ++cnt;
    }
    std::cout << cnt << std::endl;
    return 0;
}

int main(){

    std::string inputString("1");
    getline(std::cin, inputString);

    bool middleState(0);
    long counter(0);

    for(int k = inputString.size() - 1; k >= 0; k--){
        if(!middleState && inputString[k] == '0'){++counter;}
        else if(middleState && inputString[k] == '0'){counter += 2;}
        else if(inputString[k] == '1' && k > 0){++counter; middleState = 1;}
        else if(inputString[k] == '1' && middleState == 1){counter += 2;}
    }

    printf("%ld\n", counter);

    return 0;
}