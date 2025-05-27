// C++ Program to solve the n-queens problem
#include <bits/stdc++.h>
using namespace std;

// Function to check if it is safe to place
// the queen at board[row][col]
int isSafe(vector<vector<int>>& mat, 
                    int row, int col) {
    int n = mat.size();
    int i, j;

    // Check this col on upper side
    for (i = 0; i < row; i++)
        if (mat[i][col])
            return 0;

    // Check upper diagonal on left side
    for (i = row-1, j = col-1; i >= 0 && 
         j >= 0; i--, j--)
        if (mat[i][j])
            return 0;

    // Check upper diagonal on right side
    for (i = row-1, j = col+1; j < n && 
         i >= 0; i--, j++)
        if (mat[i][j])
            return 0;

    return 1;
}

int placeQueens(int row, vector<vector<int>>& mat) {
    int n = mat.size();

    // base case: If all queens are placed
    // then return true
    if(row == n) return 1;

    // Consider the row and try placing
    // queen in all columns one by one
    for(int i = 0; i < n; i++){

        // Check if the queen can be placed
        if(isSafe(mat, row, i)){
            mat[row][i] = 1;
            if(placeQueens(row + 1, mat)) 
                return 1;
            mat[row][i] = 0;
        }
    }
    return 0;
}

// Function to find the solution
// to the N-Queens problem
vector<int> nQueen(int n) {

    // Initialize the board
    vector<vector<int>> mat(n, vector<int>(n, 0));

    // If the solution exists
    if(placeQueens(0, mat)){

        // to store the columns of the queens
        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    ans.push_back(j + 1);
                }
            }
        }
        return ans;
    }
    else return {-1};
}

int main() {
    int n = 4;
    vector<int> ans = nQueen(n);
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}