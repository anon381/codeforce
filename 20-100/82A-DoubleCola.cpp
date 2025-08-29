#include <iostream>
#include <vector>
// Time Complexity: O(log n)
// Space Complexity: O(1)
#include <bits/stdc++.h>
using namespace std;
// Determines which friend will drink the nth cola in a doubling sequence.

int main(){
    vector<string> names = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    const int numFriends = names.size();
    long n = 0, power = 1;
    scanf("%ld\n",&n);
    // Loop to find the round in which the nth cola will be drunk
    while(n > power * numFriends){
        // Subtract the number of colas drunk in this round
        n -= power * numFriends;
        // Double the number of colas for the next round
        power *= 2;
    }
    // Output the name of the friend who drinks the nth cola
    cout << names[ (n-1) / power] << endl; 
    return 0;
}