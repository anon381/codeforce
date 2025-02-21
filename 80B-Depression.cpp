#include <bits/stdc++.h>

using namespace std;
// Calculates the angles of clock hands based on input time.

int main(){

    int hour(0), minute(0); scanf("%d:%d", &hour, &minute);
    // Calculate the angle of the hour hand
    double first  = 30 * (hour%12) + minute/2.0;
    // Calculate the angle of the minute hand
    double second = 6 * minute; 

    printf("%.10lf %.10lf", first, second);
    return 0;
}