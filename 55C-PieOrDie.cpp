#include <bits/stdc++.h>
using namespace std;

// Checks if any of the given k pies are close to the border of an n x m grid.
// If any pie is within 5 units of the border, prints 'YES'; otherwise, prints 'NO'.

int main(){
    int n, m, k; scanf("%d %d %d\n", &n, &m, &k);
    for(int p = 0; p < k; p++){
        int x, y; scanf("%d %d\n", &x, &y);
        if(x <= 5 || x + 4 >= n || y <= 5 || y + 4 >= m){puts("YES"); return 0;}
    }

    puts("NO");

    return 0;
}