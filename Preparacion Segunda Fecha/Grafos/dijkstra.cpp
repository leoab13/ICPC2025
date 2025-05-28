#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // n = número de nodos, m = número de aristas

    vector<vector<pair<int, int>>> g(n); // grafo: g[u] = lista de (v, peso)

    // Leer las aristas
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        // Si el grafo es no dirigido, descomenta la siguiente línea:
        // g[v].push_back({u, w});
    }

    int start = 0; // nodo desde el que queremos calcular las distancias
    vector<int> dist(n, 1e9); // distancias inicializadas en "infinito"
    dist[start] = 0;

    // Cola de prioridad: (distancia acumulada, nodo actual)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue; // si encontramos una mejor antes, ignoramos

        for (auto [v, w] : g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Mostrar las distancias desde el nodo inicial
    for (int i = 0; i < n; i++) {
        cout << "Distancia al nodo " << i << ": " << dist[i] << '\n';
    }

    return 0;
}
