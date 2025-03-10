#include <bits/stdc++.h>
using namespace std;

void sol(set<int>& cards, int x)
{
    vector<int> ans(2, 0);
    
    for (int j = 0; j < x; j++)
    {
        auto last = prev(cards.end());
        ans[j % 2] += *last;
        cards.erase(last);
    }
    
    cout << ans[0] << " " << ans[1] << endl;
}

int main()
{
    int x;
    cin >> x;
    set<int> cards;
    
    for (int i = 0; i < x; i++)
    {
        int tmp;
        cin >> tmp;
        cards.insert(tmp);
    }

    sol(cards, x);
    return 0;
}
