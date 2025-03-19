// Removes duplicate letters in rows and columns from a crossword grid.
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
#include <bits/stdc++.h>

using namespace std;

int main(){
    // Read grid dimensions
    int n(0), m(0); scanf("%d %d\n", &n, &m);
    // Initialize grid and mock grid
    vector<vector<char> > grid(n, vector<char>(m,'#'));
    vector<vector<char> > mock(n, vector<char>(m,'#'));

    // Read the grid from input
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            scanf("%c", &grid[row][col]); // Read each character
        }
        scanf("\n"); // Move to next line
    }
    // Copy grid to mock grid
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            mock[row][col] = grid[row][col];
        }
    }

    // Remove duplicates in rows and columns
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            bool cross = 0;
            // Check for duplicate in the same row
            for(int nextCol = col + 1; nextCol < m; nextCol++){
                if(grid[row][col] == grid[row][nextCol]){
                    cross = 1;
                    mock[row][nextCol] = '#'; // Mark duplicate as '#'
                }
            }
            // Check for duplicate in the same column
            for(int nextRow = row + 1; nextRow < n; nextRow++){
                if(grid[row][col] == grid[nextRow][col]){
                    cross = 1;
                    mock[nextRow][col] = '#'; // Mark duplicate as '#'
                }
            }
            // If current cell is a duplicate, mark as '#'
            if(cross){
                mock[row][col] = '#';
            }
        }
    }

    // Print the resulting grid without duplicates
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(mock[row][col] != '#'){
                printf("%c", mock[row][col]);
            }
        }
    }

    return 0;
}