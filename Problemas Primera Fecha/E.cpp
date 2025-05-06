//https://codeforces.com/gym/105873/problem/E
#include <bits/stdc++.h>
using namespace std;

void sol(vector<int> &bx, int &n, int &m)
{
    for(int i = 0; i < n; i++)
    {
        if(bx[i] >= m)
        {
            cout << (i+1) << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> bxs;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        bxs.push_back(tmp);
    }
    sol(bxs,N,M);
    return 0;
}