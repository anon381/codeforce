// Finds the smallest positive integer not present in the given set of test identifiers.
#include <bits/stdc++.h>


int main(){

    const int maxN = 3002;
    bool tests[maxN] = {0};

    int n(0); scanf("%d", &n);
    for(int k = 0; k < n; k++){int temp; scanf("%d", &temp); tests[temp] = 1;}

    for(int index = 1; index < maxN; index++){
        if(!tests[index]){printf("%d\n", index); break;}
    }
    return 0;
}
