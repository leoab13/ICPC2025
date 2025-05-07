//https://codeforces.com/contest/855/problem/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string,int> names;
    vector<string> ans;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        if(names[name] < 1)
        {
            ans.push_back("NO");
        }
        else{
            ans.push_back("Yes");
        }
        names[name]++;
    }
    for(string s : ans)
    {
        cout << s << endl;
    }

    return 0;
}