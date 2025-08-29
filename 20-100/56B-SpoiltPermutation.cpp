#include <bits/stdc++.h>
using namespace std;

// Determines the smallest range in a sequence that, if reversed, would restore the sequence to its natural order.
// If the sequence is already ordered, or no such range exists, it prints '0 0'.

int main() {
    int n;
    scanf("%d", &n);
    vector<int> permutation(n + 1);
    int left = -1, right = -1;

    // Scan through the sequence and identify the first and last positions where the value is misplaced.
    for (int i = 1; i <= n; i++) {
        scanf("%d", &permutation[i]);
        if (permutation[i] != i) {
            if (left == -1) left = i;
            right = i;
        }
    }

    // If the sequence is already sorted, print '0 0'.
    if (left == -1) {
        puts("0 0");
        return 0;
    }

    // Verify if reversing the identified segment would sort the sequence.
    bool canSort = true;
    for (int i = left; i <= right; i++) {
        if (permutation[i] != right + left - i) {
            canSort = false;
            break;
        }
    }

    if (canSort) {
        printf("%d %d\n", left, right);
    } else {
        puts("0 0");
    }

    return 0;
}