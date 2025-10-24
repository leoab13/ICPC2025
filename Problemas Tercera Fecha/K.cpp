#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long inter = max(0LL, min(b, d) - max(a, c));
        cout << inter << '\n';
    }

    return 0;
}
