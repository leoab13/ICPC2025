//https://codeforces.com/problemset/problem/996/A
#include <bits/stdc++.h>
using namespace std;

void sol(int &cash)
{
    int bills = 0;
    int n;
    while(cash >0)
    {
        if(cash >= 100)
        {
            n = 100;
        }
        else if(cash  >= 20)
        {
            n = 20;
        }
        else if(cash >= 10)
        {
            n = 10;
        }
        else if(cash >=5)
        {
            n = 5;
        }
        else if(cash >= 1)
        {
            n = 1;
        }
        
        bills += cash/n;
        
        cash -= (cash/n) * n;

        //cout << n << " " << bills << " " << cash << endl;
    }
    cout << bills << endl;
}

int main()
{
    int cash;
    cin >> cash;
    sol(cash);
    return 0;
}