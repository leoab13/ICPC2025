#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string S, T;
    cin >> S >> T;

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;  // la cadena vacía siempre está contenida

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (S[i - 1] == T[j - 1])
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
        }
    }

    // total de subsecuencias de S = 2^n
    long long total = 1;
    for (int i = 0; i < n; ++i)
        total = (total * 2) % MOD;

    // subsecuencias que NO contienen T = total - dp[n][m]
    // pero el tutorial aclara que queremos las que SÍ la contienen:
    long long result = (total - dp[n][m] + MOD) % MOD;

    cout << result << "\n";
    return 0;
}
