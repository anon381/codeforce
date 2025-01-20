#include <bits/stdc++.h>
using namespace std;

// Counts the frequency of each character in the input string.
// Calculates the sum of squares of these frequencies, representing the number of ways to choose pairs of identical symbols.

int main(){
    
    const int N = 256;
    std::vector<long long> counts(N,0);

    std::string input; getline(std::cin, input);
    for(long k = 0; k < input.size(); k++){++counts[input[k]];}

    long long total(0);
    for(long k = 0; k < N; k++){total += counts[k] * counts[k];}

    printf("%lld\n", total);

    return 0;
}