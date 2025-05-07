#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll walk_spiral(const vector<vector<ll>>& mat, int sx, int sy,
               const vector<int>& dx, const vector<int>& dy) {
    int n = mat.size();
    vector<vector<bool>> seen(n, vector<bool>(n, false));
    int x = sx, y = sy, dir = 0;
    ll sum = 0;
    for (int step = 0; step < n*n; ++step) {
        sum += mat[x][y];
        seen[x][y] = true;
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || seen[nx][ny]) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx; 
        y = ny;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<ll>> mat(n, vector<ll>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> mat[i][j];

    ll answer = 0;

    // 1) Desde esquina superior izquierda, orden: derecha, abajo, izquierda, arriba
    answer = max(answer, walk_spiral(mat, 0, 0,
        {0, 1, 0, -1}, {1, 0, -1, 0}));

    // 2) Desde esquina superior derecha, orden: abajo, izquierda, arriba, derecha
    answer = max(answer, walk_spiral(mat, 0, n-1,
        {1, 0, -1, 0}, {0, -1, 0, 1}));

    // 3) Desde esquina inferior derecha, orden: izquierda, arriba, derecha, abajo
    answer = max(answer, walk_spiral(mat, n-1, n-1,
        {0, -1, 0, 1}, {-1, 0, 1, 0}));

    // 4) Desde esquina inferior izquierda, orden: arriba, derecha, abajo, izquierda
    answer = max(answer, walk_spiral(mat, n-1, 0,
        {-1, 0, 1, 0}, {0, 1, 0, -1}));

    cout << answer << "\n";
    return 0;
}
