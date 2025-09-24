//https://codeforces.com/problemset/problem/1462/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool ok = false;
        for (int k = 0; k <= 4; k++) {
            string pref = s.substr(0, k);
            string suf = s.substr(n - (4 - k), 4 - k);
            if (pref + suf == "2020") {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
