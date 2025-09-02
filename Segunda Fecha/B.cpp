#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long fact(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res = (res * i) % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long L = 0, R = 1e18;
    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        L = max(L, l);
        R = min(R, r);
    }

    if (L > R) {
        cout << 0 << "\n";
    } else {
        long long ways = (R - L + 1) % MOD;
        ways = (ways * fact(n)) % MOD;
        cout << ways << "\n";
    }

    return 0;
}
