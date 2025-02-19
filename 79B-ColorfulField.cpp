#include <bits/stdc++.h>

using namespace std;
// Processes queries about a field, identifying waste and crop types for each cell.

int main(){

    long n, m, k, t; scanf("%ld %ld %ld %ld\n", &n, &m, &k, &t);
    vector<long> wasteCells(k, 0);

    for(long p = 0; p < k; p++){
        // Store the linear index of each waste cell
        long row, col; scanf("%ld %ld\n", &row, &col);
        wasteCells[p] = m * (row - 1) + (col - 1);
    }

    sort(wasteCells.begin(), wasteCells.end());

    for(long p = 0; p < t; p++){
        // For each query, calculate the cell number
        long row, col; scanf("%ld %ld\n", &row, &col);
        long cellNumber = m * (row - 1) + (col - 1);
        long index = 0, wasteNumber = 0;
        // Find how many waste cells are before the current cell
        while(index < k){
            if(wasteCells[index] < cellNumber){++index;}
            else if(wasteCells[index] >= cellNumber){break;}
        }

        if(wasteCells[index] == cellNumber){puts("Waste");}
        else{
            // Determine crop type based on position
            long cropNumber = cellNumber - index;
            if(cropNumber % 3 == 0){puts("Carrots");}
            else if(cropNumber % 3 == 1){puts("Kiwis");}
            else if(cropNumber % 3 == 2){puts("Grapes");}
            else{puts("Error");}
        }
    }

    return 0;
}