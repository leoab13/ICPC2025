#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> bfs_order(n);
    vector<int> position(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> bfs_order[i];
        position[bfs_order[i]] = i;  // Guardamos la posición de cada nodo en la secuencia
    }

    if (bfs_order[0] != 1) {  // La secuencia debe comenzar con 1
        cout << "No\n";
        return 0;
    }

    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;

    int index = 1;  // Índice en la secuencia de BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        vector<int> children;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                children.push_back(neighbor);
                visited[neighbor] = true;
            }
        }

        sort(children.begin(), children.end(), [&](int a, int b) {
            return position[a] < position[b];  // Ordenamos según su posición en la secuencia dada
        });

        for (int child : children) {
            if (index >= n || bfs_order[index] != child) {
                cout << "No\n";
                return 0;
            }
            q.push(child);
            index++;
        }
    }

    cout << "Yes\n";
    return 0;
}
