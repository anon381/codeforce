#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main() {

    long n, m, k; scanf("%ld %ld %ld", &n, &m, &k);
    vector<long> fv(m); 
    for(long p = 0; p < m; p++){scanf("%ld", &fv[p]);}
    vector<long> mv(k); 
    for(long p = 0; p < k; p++){scanf("%ld", &mv[p]);}

    long minSmashed(k + 1); 
    vector<long> frogs;

    for(long p = 0; p < m; p++){
        long cnt(0);
        for(long q = 0; q < k; q++){cnt += (mv[q] % fv[p] == 0);}
        if(cnt < minSmashed){
            minSmashed = cnt; 
            frogs.clear(); 
            frogs.push_back(p + 1);
        }
        else if(cnt == minSmashed){
            frogs.push_back(p + 1);
        }
    }

    printf("%ld\n", frogs.size());
    for(long p = 0; p < frogs.size(); p++){printf("%ld ", frogs[p]);}

    return 0;
}
