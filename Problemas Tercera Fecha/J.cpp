#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long x;
    cin >> x;

    long long sumJuan = 0, sumFrank = 0;
    for (auto v : a) {
        if (v >= x) sumJuan += v;
        if (v <= x) sumFrank += v;
    }

    if (sumJuan > sumFrank) {
        cout << "JUAN " << (sumJuan - sumFrank) << "\n";
    } else if (sumFrank > sumJuan) {
        cout << "FRANK " << (sumFrank - sumJuan) << "\n";
    } else {
        cout << "EMPATE 0\n";
    }

    return 0;
}
