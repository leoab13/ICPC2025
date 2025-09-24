//https://codeforces.com/problemset/problem/706/B
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> x;
int q;

void sol(vector<int>& x, vector<int>& y)
{
    for(int v : y)
    {
        int ans = upper_bound(x.begin(), x.end(), v) - x.begin();
        cout << ans << "\n";
    }
}

int main()
{
    vector<int> y;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    sort(x.begin(), x.end());
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int tmp;
        cin >> tmp;
        y.push_back(tmp);
    }
    sol(x, y);
    return 0;
}
