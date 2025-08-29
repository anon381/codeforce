#include <bits/stdc++.h>

using namespace std;
// Processes a string, removing consecutive duplicate characters.

int main(){

    string input; getline(cin, input);
    string output("");

    for(int k = 0; k < input.size(); k++){
    // If output is empty or last char is not current, add it; otherwise, remove last char
    // Time: O(n), Space: O(n) - processes each character once, output can be up to n
        if(output.empty() || output.back() != input[k]){output += input[k];}
        else{output.pop_back();}
    }

    cout << output << endl;
    return 0;
}