// Checks if a football string contains seven or more consecutive identical characters.
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>

using namespace std;

int main(){
    // Minimum number of consecutive identical characters to be dangerous
    const int dangerous = 7;
    // Read the input string
    string line; getline(cin, line);
    int state = -1; int runningSum = 0; string output = "NO";
    // Loop through each character in the string
    for(int k = 0; k < line.size(); k++){
        // If the character changes, reset the running sum
        if(line[k] != state){
            state = line[k];
            runningSum = 0;
        }
        // Increment the running sum for consecutive characters
        ++runningSum; 
        // If running sum reaches dangerous threshold, set output to YES and break
        if(runningSum >= dangerous){
            output = "YES";
            break;
        }
    }
    // Output the result
    cout << output << endl;
}