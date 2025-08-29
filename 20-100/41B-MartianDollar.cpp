#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, b; 
    scanf("%d %d\n", &n, &b);
    vector<int> price(n);
    for(int p = 0; p < n; p++) {
        scanf("%d\n", &price[p]);
    }

    int ans(b);
    for(int u = 0; u < n; u++) {
        for(int v = u + 1; v < n; v++) {
            int candidate = b - (b / price[u]) * price[u] + (b / price[u]) * price[v];
            if(candidate > ans) {
                ans = candidate;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
// or 
// from typing import List

// class Solution:
//     def max_remaining_money(self, n: int, b: int, price: List[int]) -> int:
//         ans = b
//         for u in range(n):
//             for v in range(u + 1, n):
//                 candidate = b - (b // price[u]) * price[u] + (b // price[u]) * price[v]
//                 if candidate > ans:
//                     ans = candidate
//         return ans

// if __name__ == "__main__":
//     # Read input
//     n, b = map(int, input().split())
//     price = list(map(int, input().split()))
    
//     # Create an instance of the Solution class
//     sol = Solution()
    
//     # Compute and print the result
//     print(sol.max_remaining_money(n, b, price))

