#include <bits/stdc++.h>
using namespace std;

struct Node {
    int cost, x, y;
    bool operator>(const Node &o) const { return cost > o.cost; }
};

inline bool isValid(int x, int y, int n, int m, const vector<string> &grid) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '1';
}

inline void moveRobot(int &x, int &y, char dir) {
    if (dir == 'U') --x;
    else if (dir == 'D') ++x;
    else if (dir == 'L') --y;
    else if (dir == 'R') ++y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    int K;
    cin >> K;
    vector<string> cmds(K);
    for (int i = 0; i < K; ++i) cin >> cmds[i];


    vector<string> useful;
    useful.reserve(K);
    for (auto &s : cmds) {
        bool ok = false;
        for (char c : s)
            if (c == 'U' || c == 'D' || c == 'L' || c == 'R') {
                ok = true;
                break;
            }
        if (ok) useful.push_back(s);
    }
    cmds.swap(useful);
    K = cmds.size();

    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(m, INF));

    vector<vector<vector<array<int, 3>>>> cmdDest(
        K, vector<vector<array<int, 3>>>(
               n, vector<array<int, 3>>(m, {0, 0, 0})));

    for (int k = 0; k < K; ++k) {
        const string &cmd = cmds[k];
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (grid[x][y] == '1') {
                    cmdDest[k][x][y] = {x, y, 0};
                    continue;
                }
                int nx = x, ny = y, steps = 0;
                for (char c : cmd) {
                    int tx = nx, ty = ny;
                    moveRobot(tx, ty, c);
                    if (isValid(tx, ty, n, m, grid)) {
                        nx = tx;
                        ny = ty;
                        ++steps;
                    }
                }
                cmdDest[k][x][y] = {nx, ny, steps};
            }
        }
    }


    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[sx][sy] = 0;
    pq.push({0, sx, sy});

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top();
        pq.pop();
        if (cost > dist[x][y]) continue;
        if (x == gx && y == gy) {
            cout << cost << "\n";
            return 0;
        }

        for (int k = 0; k < K; ++k) {
            auto [nx, ny, steps] = cmdDest[k][x][y];
            if (steps == 0) continue;
            int newCost = cost + steps;
            if (newCost < dist[nx][ny]) {
                dist[nx][ny] = newCost;
                pq.push({newCost, nx, ny});
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
