#include <bits/stdc++.h>
using namespace std;

struct State {
    int dist, x, y;
    bool operator>(const State& o) const {
        return dist > o.dist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    int Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;

    int K;
    cin >> K;
    vector<string> orders(K);
    for (int i = 0; i < K; i++) cin >> orders[i];

    // Precompute transitions
    // next[x][y][i] = final pos after applying orders[i]
    vector<vector<vector<pair<int,int>>>> nxt(N, vector<vector<pair<int,int>>>(M, vector<pair<int,int>>(K)));

    auto inside = [&](int x,int y){ return x>=0 && x<N && y>=0 && y<M; };

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (grid[x][y] == '1') continue;
            for (int i = 0; i < K; i++) {
                int cx = x, cy = y;
                for (char c : orders[i]) {
                    int nx = cx, ny = cy;
                    if (c == 'U') nx--;
                    else if (c == 'D') nx++;
                    else if (c == 'L') ny--;
                    else if (c == 'R') ny++;
                    if (inside(nx, ny) && grid[nx][ny] == '0') {
                        cx = nx; cy = ny;
                    }
                    // si no es válido, se queda quieto
                }
                nxt[x][y][i] = {cx, cy};
            }
        }
    }

    const int INF = 1e9;
    vector<vector<int>> dist(N, vector<int>(M, INF));
    priority_queue<State, vector<State>, greater<State>> pq;
    dist[Ax][Ay] = 0;
    pq.push({0, Ax, Ay});

    while (!pq.empty()) {
        auto [d, x, y] = pq.top(); pq.pop();
        if (d > dist[x][y]) continue;
        if (x == Bx && y == By) {
            cout << d << "\n";
            return 0;
        }
        for (int i = 0; i < K; i++) {
            auto [nx, ny] = nxt[x][y][i];
            int nd = d + (int)orders[i].size();
            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                pq.push({nd, nx, ny});
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}
