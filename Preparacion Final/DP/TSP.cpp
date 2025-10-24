#include <bits/stdc++.h>
using namespace std;

int main() {
    // Ejemplo de matriz de distancias entre ciudades
    vector<vector<int>> distances = {
        {0, 20, 42, 35},
        {20, 0, 30, 34},
        {42, 30, 0, 12},
        {35, 34, 12, 0}
    };

    int n = distances.size(); // Número de ciudades
    int N = 1 << n;           // Número total de subconjuntos

    // DP y parent
    vector<vector<double>> dp(N, vector<double>(n, INFINITY));
    vector<vector<int>> parent(N, vector<int>(n, -1));

    // Caso base: empezando desde la ciudad 0
    dp[1][0] = 0;

    // Llenar la tabla DP
    for (int mask = 0; mask < N; mask++) {
        for (int last = 0; last < n; last++) {
            if (!(mask & (1 << last))) continue;
                        /*
                        Se hace el desplazamiento de bits a la izquierda de 0 a N-1
            0001
        &   0001
        ------
            0001
           !0001 -> false
            */
            for (int next = 0; next < n; next++) {
                if (mask & (1 << next)) continue;
                int new_mask = mask | (1 << next);
                double new_dist = dp[mask][last] + distances[last][next];
                if (new_dist < dp[new_mask][next]) {
                    dp[new_mask][next] = new_dist;
                    parent[new_mask][next] = last;
                }
            }
        }
    }

    // Encontrar el costo mínimo y ciudad final
    double min_cost = INFINITY;
    int end_city = -1;
    int full_mask = N - 1;

    for (int last = 1; last < n; last++) {
        double cost = dp[full_mask][last] + distances[last][0];
        if (cost < min_cost) {
            min_cost = cost;
            end_city = last;
        }
    }

    // Reconstruir el recorrido óptimo
    vector<int> tour;
    int mask = full_mask;
    int last = end_city;

    while (mask) {
        tour.push_back(last);
        int new_last = parent[mask][last];
        mask ^= (1 << last);
        last = new_last;
    }

    reverse(tour.begin(), tour.end());
    tour.push_back(0); // Volver a la ciudad inicial

    // Imprimir tabla DP final
    cout << "Final DP Table:\n";
    for (int mask = 0; mask < N; mask++) {
        cout << "mask = " << bitset<4>(mask) << ": ";
        for (int j = 0; j < n; j++) {
            if (dp[mask][j] == INFINITY)
                cout << "INF ";
            else
                cout << dp[mask][j] << " ";
        }
        cout << "\n";
    }

    // Imprimir tour óptimo y costo mínimo
    cout << "\nOptimal Tour: ";
    for (int city : tour) cout << city << " ";
    cout << "\nMinimum Cost: " << min_cost << endl;

    return 0;
}
