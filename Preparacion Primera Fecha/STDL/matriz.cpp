//una matriz de mxn hay que encontrar el camino de costo minimo de [0,0] a [m,n]
#include <bits/stdc++.h>
using namespace std;

int sol(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> dp(n, 0);
    dp[0] = grid[0][0];
    for (int j = 1; j < n; j++) {
        dp[j] = dp[j - 1] + grid[0][j];
    }
    for (int i = 1; i < m; i++) {
        dp[0] += grid[i][0];
        for (int j = 1; j < n; j++) {
            dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1];
}

int main() {
    vector<vector<int>> grid;
    int m, n, tmp;
    cin >> m >> n;
    
    for (int i = 0; i < m; i++) {
        vector<int> vtmp;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            vtmp.push_back(tmp);
        }
        grid.push_back(vtmp);
    }
    cout << sol(grid) << endl;
    return 0;
}

