//https://codeforces.com/contest/520/problem/A
#include <bits/stdc++.h>
using namespace std;

void sol(string &cad)
{
    set<char> s;
    string l = "qwertyuioplkjhgfdsazxcvbnm";
    for(char c : cad)
    {
        c = tolower(c);
        s.insert(c);
    }
    if(s.size() >= l.size())
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    string cad;
    cin >> cad;
    sol(cad);
    return 0;
}