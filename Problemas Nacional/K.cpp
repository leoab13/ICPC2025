#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Maximiza (w+a) * (h+k-a) en a ∈ [0, k]
ll bestTwoKing(ll w, ll h, ll k) {
    // Punto crítico de la parábola
    long double a0 = ((long double)h - (long double)w + (long double)k) / 2.0;

    // Limitar al rango válido
    long double a_clamped = max((long double)0, min((long double)k, a0));

    ll a1 = floor(a_clamped);
    ll a2 = ceil(a_clamped);

    auto f = [&](ll a) -> ll {
        if (a < 0 || a > k) return 0LL;
        return (w + a) * (h + (k - a));
    };

    return max(f(a1), f(a2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> kings(n);

    for (int i = 0; i < n; i++)
        cin >> kings[i].first >> kings[i].second;

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    ll maxX = LLONG_MIN, maxY = LLONG_MIN;
    ll minX = LLONG_MAX, minY = LLONG_MAX;

    for (auto &p : kings) {
        maxX = max(maxX, p.first);
        minX = min(minX, p.first);

        maxY = max(maxY, p.second);
        minY = min(minY, p.second);
    }

    ll w = maxX - minX + 1;
    ll h = maxY - minY + 1;

    // Caso 1: repartir k entre incrementar w o incrementar h
    ll bestTwo = bestTwoKing(w, h, k);

    // Caso 2: mover un rey hasta ±k en ambas direcciones y ver si crea un rectángulo más grande
    ll bestOne = w * h;

    const ll dx[4] = {-1, -1, 1, 1};
    const ll dy[4] = {-1, 1, -1, 1};

    for (auto &p : kings) {
        ll x = p.first, y = p.second;
        for (int t = 0; t < 4; t++) {
            ll nx = x + dx[t] * k;
            ll ny = y + dy[t] * k;

            ll wc = max(maxX, nx) - min(minX, nx) + 1;
            ll hc = max(maxY, ny) - min(minY, ny) + 1;

            bestOne = max(bestOne, wc * hc);
        }
    }

    cout << max(bestOne, bestTwo) << "\n";
    return 0;
}
