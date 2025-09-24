//https://codeforces.com/problemset/problem/796/A
#include <bits/stdc++.h>
using namespace std;

void sol(int &n,int &m, int &k, vector<int> &a)
{
    // m where the girl lives
    // k money
    // n hauses
    int distCurr = INT16_MAX;
    int distPrev = INT16_MAX;
    int ans;
    for(int i = 0; i < n; i++)
    {
        if((a[i] <= k) && a[i] != 0)
        {
           distPrev = distCurr; 
           distCurr = max((m - 1),i) - min((m - 1),i);
            if(distCurr < distPrev)
            {
                ans= distCurr;
            }
        }
    }
    cout << ans * 10 << endl;
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sol(n,m,k,a);
    return 0;
}