//fibonacci secuence using dinamic programming 
#include <bits/stdc++.h>
using namespace std;
vector<int> memo(100, 0);

int solution(int &n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int recursiveSolutiondp(int n)
{
    memo[0] = 0;
    memo[1] = 1;
    if (memo[n] != 0)
        return memo[n];
    memo[n] = recursiveSolutiondp(n - 1) + recursiveSolutiondp(n - 2);
    return memo[n];
}

int main()
{
    int n;
    cin >> n;
    cout << solution(n) << "\n";
    cout << recursiveSolutiondp(n) << "\n";
    return 0;
}