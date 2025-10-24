//https://codeforces.com/gym/106063/problem/F
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int cost, x, y;
    bool operator>(const Node& o) const { return cost > o.cost; }
};

bool isValid(int x, int y, int n, int m, const vector<string>& grid) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '1';
}

void moveRobot(int &x, int &y, char dir) {
    if (dir == 'U') x--;
    else if (dir == 'D') x++;
    else if (dir == 'L') y--;
    else if (dir == 'R') y++;
}

int dijkstraMemo(int sx, int sy, int gx, int gy,
                 const vector<string>& grid,
                 const vector<string>& cmds) {
    int n = grid.size(), m = grid[0].size();
    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    dist[sx][sy] = 0;

    // Memo: resultado de ejecutar cada comando desde cada celda
    // memo[cmd_idx][x][y] = {nx, ny, steps}
    vector<vector<vector<array<int,3>>>> memo(cmds.size(),
        vector<vector<array<int,3>>>(n, vector<array<int,3>>(m, {-1,-1,-1})));

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, sx, sy});

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top();
        pq.pop();

        if (cost > dist[x][y]) continue;
        if (x == gx && y == gy) return cost; // llegó justo al final de una orden

        for (int i = 0; i < (int)cmds.size(); ++i) {
            if (memo[i][x][y][0] == -1) {
                int nx = x, ny = y, steps = 0;
                for (char c : cmds[i]) {
                    int tx = nx, ty = ny;
                    moveRobot(tx, ty, c);
                    if (isValid(tx, ty, n, m, grid)) {
                        nx = tx; ny = ty;
                    }
                    steps++;
                }
                memo[i][x][y] = {nx, ny, steps};
            }

            auto [nx, ny, steps] = memo[i][x][y];
            int newCost = cost + steps;

            if (newCost < dist[nx][ny]) {
                dist[nx][ny] = newCost;
                pq.push({newCost, nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;

    int K;
    cin >> K;
    vector<string> cmds(K);
    for (int i = 0; i < K; i++) cin >> cmds[i];

    cout << dijkstraMemo(Ax, Ay, Bx, By, grid, cmds) << "\n";
    return 0;
}
