// Time Complexity: O(n)
// Space Complexity: O(1)
#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

using namespace std;
// Generates and prints a sequence of characters based on input n, alternating patterns for even and odd n.

int main(){

    int n(0); scanf("%d", &n);
    char first = 'x', last = 'y';
    int count(0);

    if(n%2 == 0){

        for(int k = 0; k < n/2; k++){printf("%c%c", (count)%2 + 'a', (count)%2 + 'a'); ++count;}; puts("");
        for(int k = 0; k < n/2; k++){printf("%c%c", (count)%2 + 'c', (count)%2 + 'c'); ++count;}; puts("");

        printf("%c", first); for(int k = 0; k < n/2 - 1; k++){printf("%c%c", (count)%2 + 'f', (count)%2 + 'f'); ++count;}; printf("%c\n", last);
        printf("%c", first); for(int k = 0; k < n/2 - 1; k++){printf("%c%c", (count)%2 + 'm', (count)%2 + 'm'); ++count;}; printf("%c\n", last);

    }

    else if(n%2 == 1){

        char count = 'b';
        printf("%c", first); for(int k = 0; k < n/2; k++){printf("%c%c", (count)%2 + 'a', (count)%2 + 'a'); ++count;}; puts("");
        printf("%c", first); for(int k = 0; k < n/2; k++){printf("%c%c", (count)%2 + 'c', (count)%2 + 'c'); ++count;}; puts("");

        for(int k = 0; k < n/2; k++){printf("%c%c", (count)%2 + 'f', (count)%2 + 'f'); ++count;}; printf("%c\n", last);
        for(int k = 0; k < n/2; k++){printf("%c%c", (count)%2 + 'm', (count)%2 + 'm'); ++count;}; printf("%c\n", last);

    }

    return 0;
}