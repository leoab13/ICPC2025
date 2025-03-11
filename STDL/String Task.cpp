//https://codeforces.com/problemset/problem/118/A
#include <bits/stdc++.h>
using namespace std;

void sol(string &cad)
{
    string v = "aoyeuiAOYEUI";
    string ans;
    for(char c : cad)
    {
        c = tolower(c);
        if(v.find(c) == string::npos)
        {
            ans+= ".";
            ans+=c;
        }
    }
    cout << ans << endl;
}

int main()
{
    string cad;
    cin >> cad;
    sol(cad);
    return 0;
}