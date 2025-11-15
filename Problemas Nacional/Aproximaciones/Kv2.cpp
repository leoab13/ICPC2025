#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Devuelve span en X (maxX - minX)
ll getX(const vector<pair<ll,ll>> &k, ll &minX, ll &maxX) {
    minX = k[0].first;
    maxX = k[0].first;
    for (auto &c : k) {
        if (c.first < minX) minX = c.first;
        if (c.first > maxX) maxX = c.first;
    }
    return maxX - minX;
}

// Devuelve span en Y (maxY - minY)
ll getY(const vector<pair<ll,ll>> &k, ll &minY, ll &maxY) {
    minY = k[0].second;
    maxY = k[0].second;
    for (auto &c : k) {
        if (c.second < minY) minY = c.second;
        if (c.second > maxY) maxY = c.second;
    }
    return maxY - minY;
}

// Comprueba si existe una pieza que con 1 movimiento pueda convertirse en esquina
// xory: salida -> si true, hay que acercar en X; si false, en Y (según tu convención)
void isPosibleToMakeCorner(const vector<pair<ll,ll>> &k, ll minX, ll maxX, ll minY, ll maxY, bool &xory, bool &possibleCorner) {
    possibleCorner = false;
    xory = false;
    for (auto &c : k) {
        ll a = c.first;
        ll b = c.second;
        // Si la pieza está en una frontera X (minX o maxX) y su Y está adyacente a minY o maxY
        if ((a == minX || a == maxX) &&
            ( (b - 1 == minY) || (b + 1 == minY) || (b - 1 == maxY) || (b + 1 == maxY) )) {
            xory = false; // falso = el max esta en X y se tiene que acercar en Y
            possibleCorner = true;
            break;
        }
        // Si la pieza está en una frontera Y y su X está adyacente a minX o maxX
        if ((b == minY || b == maxY) &&
            ( (a - 1 == minX) || (a + 1 == minX) || (a - 1 == maxX) || (a + 1 == maxX) )) {
            xory = true; // true = el max esta en Y y se tiene que acercar en X
            possibleCorner = true;
            break;
        }
    }
}

// Comprueba si ya existe una pieza exactamente en alguna esquina del bounding box
bool isCornerPresent(const vector<pair<ll,ll>> &k, ll minX, ll maxX, ll minY, ll maxY) {
    for (auto &c : k) {
        if ((c.first == minX && c.second == minY) ||
            (c.first == minX && c.second == maxY) ||
            (c.first == maxX && c.second == minY) ||
            (c.first == maxX && c.second == maxY)) {
            return true;
        }
    }
    return false;
}

// Tu heurística central: calcula área según tu lógica de casos
long long solution(vector<pair<ll,ll>> kings, ll k) {
    // reiniciar banderas locales
    bool corner = false;
    bool possibleCorner = false;

    // split aproximado de movimientos
    ll movesX = k / 2;
    ll movesY = k - movesX;

    ll minX, maxX, minY, maxY;
    ll xSpan = getX(kings, minX, maxX) + 1; // lado X (anchura en celdas)
    ll ySpan = getY(kings, minY, maxY) + 1; // lado Y (altura en celdas)

    // detectar si hay esquina ocupada
    corner = isCornerPresent(kings, minX, maxX, minY, maxY);
    if (!corner) {
        isPosibleToMakeCorner(kings, minX, maxX, minY, maxY, /*out*/ *(new bool), possibleCorner);
        // note: above line used a throwaway bool for xory; we'll recompute xory below if needed
    }

    bool xory = false;
    if (!corner && possibleCorner) {
        // recompute xory properly (we need its value)
        isPosibleToMakeCorner(kings, minX, maxX, minY, maxY, xory, possibleCorner);
    }

    ll x = xSpan;
    ll y = ySpan;

    // Aplica la lógica de casos (tu heurística)
    if (x == y) { // es cuadrado
        if (corner) {
            // si hay esquina, mover diagonalmente k veces aumenta ambos lados
            x += k;
            y += k;
        } else {
            if (possibleCorner) {
                // si hay una pieza que con 1 movimiento puede volver esquina
                // consume 1 movimiento para crear la esquina y luego aplica el resto como diagonal
                x += 1; k -= 1;
                if (k < 0) k = 0;
                x += k;
                y += k;
            } else {
                // repartir movimientos entre X y Y (heurística)
                x += movesX;
                y += movesY;
            }
        }
    } else { // rectángulo (x != y)
        if (corner) {
            // si esquina ocupada, capacidad de incrementar ambos lados (diagonal)
            x += k;
            y += k;
        } else {
            if (possibleCorner) {
                if (!xory) {
                    // incrementar en Y primero para crear esquina
                    y += 1;
                    k -= 1;
                    if (k < 0) k = 0;
                } else {
                    // incrementar en X primero
                    x += 1;
                    k -= 1;
                    if (k < 0) k = 0;
                }
                // tras crear esquina, gastar el resto diagonalmente (tu heurística)
                x += k;
                y += k;
            } else {
                // no hay esquina ni posible esquina: heurística de repartir movimientos
                // incrementar preferentemente el lado más grande con más movimientos
                ll maxv = max(x, y) + max(movesX, movesY);
                ll minv = min(x, y) + min(movesX, movesY);
                if (x >= y) {
                    x = maxv;
                    y = minv;
                } else {
                    x = minv;
                    y = maxv;
                }
            }
        }
    }

    // area final
    return x * y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    if (!(cin >> n >> k)) return 0;
    vector<pair<ll,ll>> kings;
    kings.reserve(n);
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        // Importante: invertir Y porque en el enunciado Y crece hacia abajo.
        // Si tu visualización/figura usa y<0 arriba, esto normaliza a coordenadas cartesianas
        kings.emplace_back(x, -y);
    }

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    cout << solution(kings, k) << '\n';
    return 0;
}
