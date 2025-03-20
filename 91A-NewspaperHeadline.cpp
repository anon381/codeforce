// Time Complexity: O(n + m)
// Space Complexity: O(n)
#include <bits/stdc++.h>

using namespace std;

int main(){

    const int N = 26; 

    string source, target;
    getline(cin, source);
    getline(cin, target);

    vector<vector<long>> pos(N);
    for(size_t p = 0; p < source.size(); p++){pos[source[p] - 'a'].push_back(p);}

    long count(1);
    long index = -1;
    for(size_t p = 0; p < target.size(); p++){
        int letter = target[p] - 'a'; 
        if(pos[letter].empty()){count = -1; break;}
        vector<long>::iterator posPointer = upper_bound(pos[letter].begin(), pos[letter].end(), index);
        if(posPointer == pos[letter].end()){++count; index = -1;}
        index = *std::upper_bound(pos[letter].begin(), pos[letter].end(), index);
    }

    cout << count << endl;

    return 0;
}