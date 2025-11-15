#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> tasks;
    for(int i = 0 ; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        tasks.push_back(tmp);
    }
    int ans = 0;
    int last = -1;
    for(int i = 0 ; i < n  ; i ++)
    {
        if(tasks[i] > last )
        {
            ans++;
            last = tasks[i];
        }
    }
    cout << ans << "\n";
    return 0;
}