#include <bits/stdc++.h>
using namespace std;

void solution(int &l, int &r, int &k)
{
        int c = floor(r/k) - floor((l - 1)/k);
        cout << c << endl;
}

int main()
{
    int l,r,k;
    cin >> l >> r >> k;
    solution(l,r,k);
    return 0;
}