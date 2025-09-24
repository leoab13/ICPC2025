//https://codeforces.com/problemset/problem/1385/A
#include <bits/stdc++.h>
using namespace std;

void sol(vector<vector<int>> cases)
{
    for(vector<int> cas: cases)
    {
        sort(cas.begin(), cas.end());
        if((cas[0] <= cas[1]) && (cas[1] == cas[2]))
        {
            int m = 1;
            if(cas[0] == 1)
            {
                m = 0;
            }
            cout << "YES"<< endl;
            if(cas[0] == cas[1] && cas[1] == cas[2])
            {
                cout << cas[0] << " " << cas[0] << " " << cas[0] <<endl;
            }
            else{
            cout << cas[0] - m << " " << cas[0] << " " << cas[1] <<endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    vector<vector<int>> cases;
    for(int i = 0 ; i < t; i++)
    {
        vector<int> tmpVec;
        for(int j = 0; j < 3; j++)
        {
            int tmpNum;
            cin >> tmpNum;
            tmpVec.push_back(tmpNum);
        }
        cases.push_back(tmpVec);
    }
    sol(cases);
    return 0;
}