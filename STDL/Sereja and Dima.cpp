//https://codeforces.com/contest/381/problem/A
#include <bits/stdc++.h>
using namespace std;


//SOLUCION CON DOS PUNTEROS
void sol(vector<int> & cards)
{
    int n = cards.size();
    vector<int> ans = {0,0};
    int c = 0, d = 1;
    int a = cards[c];
    int b = cards[n -d];
    int m;
    for(int i = 0; i < n; i ++)
    {
        m = max(a,b);
        ans[i%2] += m;
        if(m == a)
        {
            a = cards[++c];
        }
        else{
            b = cards[n - (++d)];
        }
    }
    cout << ans[0] << " " << ans[1];
}

int main()
{
    int x;
    cin >> x;
    vector<int> cards;
    int tmp;
    for(int i = 0; i < x; i++)
    {
        cin >> tmp;
        cards.push_back(tmp);
    }
    sol(cards);
    return 0;
}
