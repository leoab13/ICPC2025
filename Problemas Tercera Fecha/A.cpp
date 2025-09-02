#include <bits/stdc++.h>
using namespace std;

void sol(int &n, int &sum)
{
    int c = 0;
    for(int i = n; i > 0; i--)
    {
        if(sum%i == 0)
        {
            break;
        }
        else{
            c++;
        }
    }
    cout << c << endl;
}

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    sol(n,sum);
    return 0;
}