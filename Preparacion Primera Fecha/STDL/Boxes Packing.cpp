//https://codeforces.com/contest/903/problem/C
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> m;
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++)
    {
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }
    cout << prev(m.end())->second << endl;
    return 0;
}