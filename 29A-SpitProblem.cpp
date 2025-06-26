// Normalizes spit events to (start, distance) and checks for a pair with identical landing meeting points.
#include <bits/stdc++.h>

using namespace std;
int main() {
    long n(0); 
    scanf("%ld", &n);
    vector<pair<long, long>> events;
    for(long k = 0; k < n; k++) {
        long pos(0), spit(0); 
        scanf("%ld %ld", &pos, &spit);
        if(spit < 0) { 
            spit *= -1; 
            pos -= spit;
        }
        events.push_back(pair<long,long>(pos, spit));
    }
    sort(events.begin(), events.end());
    bool mutual(0);
    for(long k = 0; k < n - 1; k++) {
        if(events[k].first == events[k+1].first && events[k].second == events[k+1].second) {
            mutual = 1; 
            break;
        }
    }
    if(mutual) { 
        puts("YES"); 
    } 
    else { 
        puts("NO"); 
    }
    return 0;
}
