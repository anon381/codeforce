// Time Complexity: O(n)
// Space Complexity: O(n)
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    long n; cin >> n;
    vector<long> a(n); 
    long total(0);
    for(long p = 0; p < n; p++){
        cin >> a[p];
        total += a[p];
    }

    int res(0), diff(0), from(0), to(0);
    if(total % n != 0){
        res = 0;
    }
    else{
        long vol = total / n;
        long good(0);
        for(long p = 0; p < n; p++){
            if(a[p] > vol){
                to = p;
            }
            else if(a[p] < vol){
                from = p;
            }
            else{
                ++good;
            }
        }

        if(good == n){
            res = 1;
        }
        else if(good != n - 2){
            res = 0;
        }
        else{
            diff = a[to] - vol;
            ++from;
            ++to;
            res = 2;
        }
    }

    if(res == 0){std::cout << "Unrecoverable configuration." << std::endl;}
    else if(res == 1){std::cout << "Exemplary pages." << std::endl;}
    else if(res == 2){std::cout << diff << " ml. from cup #" << from << " to cup #" << to << "." << std::endl;}

    return 0;
}