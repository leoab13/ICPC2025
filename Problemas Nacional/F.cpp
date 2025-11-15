#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define SIZE(c) int((c).size())
typedef long long tint;
const int DIGITS = 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    map<tint, int> f;
    forn(t, SIZE(s) - DIGITS)
    {
        f[2]++;
        f[5]++;
    }
    tint Y = stoll(s.substr(0, 10));
    for (tint p = 2; p * p <= Y; p++)
    {
        while (Y % p == 0)
        {
            Y /= p;
            f[p]++;
        }
    }
    if (Y > 1)
        f[Y]++;
    cout << SIZE(f) << "\n";
    for (auto it : f)
        cout << it.first << " " << it.second << "\n";
    return 0;
}