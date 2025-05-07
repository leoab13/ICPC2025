#include <bits/stdc++.h>
using namespace std;

void sol(string &cad)
{
    int n = 0,m = 0;
    for(char c : cad)
    {
        if(c == '1')
        {
            n++;
        }
        else{
            m++;
        }
    }
    cout << abs(n - m)<< endl;
}

int main()
{
    int n;
    string cad;
    cin >> n;
    cin >> cad;
    sol(cad);
    return 0;
}