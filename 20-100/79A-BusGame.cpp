#include <bits/stdc++.h>

using namespace std;
// Simulates a turn-based bus game between two players, updating resources and determining the winner.

int main(){

    long hundreds(0), tens(0); scanf("%ld %ld", &hundreds, &tens);
    bool loser(0);

    while(true){
    // Time: O(1) per turn, Space: O(1) - loop runs until resources are depleted

        //Ciel
    // Ciel's turn: try to subtract resources in priority order
        if(hundreds >= 2 && tens >= 2){hundreds -= 2; tens -= 2;}
        else if(hundreds >= 1 && tens >= 12){hundreds -= 1; tens -= 12;}
        else if(tens >= 22){tens -= 22;}
        else{loser = 1; break;}

        //Hanako
    // Hanako's turn: try to subtract resources in priority order
        if(tens >= 22){tens -= 22;}
        else if(tens >= 12 && hundreds >= 1){hundreds -= 1; tens -= 12;}
        else if(tens >= 2 && hundreds >= 2){hundreds -= 2; tens -= 2;}
        else{loser = 0; break;}
    }

    loser ? puts("Hanako") : puts("Ciel");

    return 0;
}