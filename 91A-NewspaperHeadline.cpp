// Finds the minimum number of passes to form a target string from a source string.
// Time Complexity: O(n + m)
// Space Complexity: O(n)
#include <bits/stdc++.h>

using namespace std;

int main(){
    // Number of lowercase letters
    const int N = 26; 

    // Read source and target strings
    string source, target;
    getline(cin, source);
    getline(cin, target);

    // Store positions of each letter in the source string
    vector<vector<long>> pos(N);
    for(size_t p = 0; p < source.size(); p++){
        pos[source[p] - 'a'].push_back(p); // Record position for each character
    }

    long count(1); // Number of passes needed
    long index = -1; // Current position in source
    // Loop through each character in the target string
    for(size_t p = 0; p < target.size(); p++){
        int letter = target[p] - 'a'; 
        // If the letter does not exist in source, impossible
        if(pos[letter].empty()){
            count = -1;
            break;
        }
        // Find the next occurrence of the letter after current index
        vector<long>::iterator posPointer = upper_bound(pos[letter].begin(), pos[letter].end(), index);
        // If not found, need another pass through source
        if(posPointer == pos[letter].end()){
            ++count;
            index = -1;
        }
        // Update index to the found position
        index = *std::upper_bound(pos[letter].begin(), pos[letter].end(), index);
    }

    // Output the number of passes needed
    cout << count << endl;

    return 0;
}