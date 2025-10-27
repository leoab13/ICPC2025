#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n): n(n), bit(n+1, 0) {}

    void update(int i, long long x) {
        for (; i <= n; i += i & -i)
            bit[i] ^= x; // XOR en lugar de suma
    }

    long long query(int i) {
        long long res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    long long rangeXor(int l, int r) {
        return query(r) ^ query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    Fenwick fw(n);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        fw.update(i, a[i]);  // inicializar árbol con XOR
    }

    while (q--) {
        char type;
        cin >> type;
        if (type == 'R') {
            int k; long long x;
            cin >> k >> x;
            // actualizar el valor en la posición k sumando x
            long long newVal = a[k] + x;
            fw.update(k, a[k]);  // quitar el valor anterior
            fw.update(k, newVal); // agregar el nuevo
            a[k] = newVal;
        } else { // 'P'
            int l, r;
            cin >> l >> r;
            long long nim = fw.rangeXor(l, r);
            if (nim == 0) cout << "JUAN\n";
            else cout << "FRANK\n";
        }
    }

    return 0;
}
