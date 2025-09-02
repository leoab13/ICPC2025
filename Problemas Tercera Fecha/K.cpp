#include <bits/stdc++.h>
using namespace std;

void sol(vector< long int> &v)
{
    long int ans = 0;
    if((v[2] >= v[0]) && (v[2] <= v[1]) || (v[0] >= v[2] && ( (v[0] <= v[3]) )))
    {
        ans =  min(v[1],v[3]) - max(v[0],v[2]);
    }
    ans = abs(ans);
    cout << ans << endl;
}



int main()
{
    int n;
    vector<vector< long int>> cas;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        vector<long int> tmp;
        for(int j = 0; j < 4; j++)
        {
            long int t;
            cin >> t;
            tmp.push_back(t);
        }
        cas.push_back(tmp);
    }
    for(vector< long int> x : cas)
    {
        sol(x);
    }
}