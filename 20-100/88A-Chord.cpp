// Determines if three musical notes form a major, minor, or strange chord.
// Time Complexity: O(1)
// Space Complexity: O(1)
#include <bits/stdc++.h>

using namespace std;

int main(){
    // Number of notes in an octave
    const int M = 12;

    // Map each note to its corresponding integer value
    map<string, int> notes;
    notes["C"] = 0; notes["C#"] = 1;
    notes["D"] = 2; notes["D#"] = 3;
    notes["E"] = 4; 
    notes["F"] = 5; notes["F#"] = 6;
    notes["G"] = 7; notes["G#"] = 8;
    notes["A"] = 9; notes["B"] = 10; notes["H"] = 11;

    // Read the three notes from input
    string x, y, z; cin >> x >> y >> z;
    vector<int> s; 
    // Convert notes to their integer values and store in vector
    s.push_back(notes[x]); s.push_back(notes[y]); s.push_back(notes[z]);
    // Sort the notes to simplify interval calculation
    sort(s.begin(), s.end()); 
    // Add the first note + 12 to handle octave wrap-around
    s.push_back(s[0] + M);

    // Check for major chord intervals
    if((s[1] - s[0] == 4 && s[2] - s[1] == 3) || 
       (s[2] - s[1] == 4 && s[3] - s[2] == 3) || 
       (s[3] - s[2] == 4 && s[1] - s[0] == 3)){
        puts("major");
    }
    // Check for minor chord intervals
    else if((s[1] - s[0] == 3 && s[2] - s[1] == 4) || 
            (s[2] - s[1] == 3 && s[3] - s[2] == 4) || 
            (s[3] - s[2] == 3 && s[1] - s[0] == 4)){
        puts("minor");
    }
    // If neither, output "strange"
    else{
        puts("strange");
    }

    return 0;
}