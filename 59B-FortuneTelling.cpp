
#include <bits/stdc++.h>
using namespace std;

// This program reads a list of integers and calculates a special sum based on the parity of odd numbers.
// If there are no odd numbers, outputs 0.
// If the count of odd numbers is even, subtracts the smallest odd from the total sum; otherwise, outputs the total sum.

int main(){

    int n(0); scanf("%d", &n);

    int temp(0), total(0), minOdd(101), numOdds(0);
    for(int k = 0; k < n; k++){
        scanf("%d", &temp);
        total += temp;
        if(temp % 2 == 1){++numOdds; if(temp < minOdd){minOdd = temp;}}
    }

    if(minOdd > 100){puts("0");}
    else if(numOdds % 2 == 0){printf("%d\n", total - minOdd);}
    else if(numOdds % 2 == 1){printf("%d\n", total);}

    return 0;
}