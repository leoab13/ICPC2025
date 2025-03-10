
#include <bits/stdc++.h>
using namespace std;

void sol(set<int>& cards, int x)
{
    vector<int> ans = {0,0};
    for(int j = 0; j < x; j++)
    {
        if(j%2 == 0)
        {
            ans[0] +=  *cards.end();
        }
        else
        {
            ans[1] += *cards.end();
        }
        cards.erase(cards.end());
    }
    cout << ans[0] << ans[1] << endl;
}

int main()
{
    int x;
    cin >> x;
    set<int> cards;
    int tmp;
    for(int i = 0; i < x ; i++)
    {
        cin >> tmp;
        cards.insert(tmp);
    }
    sol(cards,x);
    return 0;
}