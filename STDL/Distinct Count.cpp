//https://www.hackerearth.com/practice/data-structures/trees/
//binary-search-tree/practice-problems/algorithm/distinct-count/discussion/
//c-solution-using-uno-2545e301/?purpose=signup&source=problem-page&update=google
#include <bits/stdc++.h>
using namespace std;
string sol(vector<int> &n)
{
    int t = n.size() - 1;
    int x = n[t];
    n.pop_back();
    set<int> s;
    for(int a : n)
    {
        s.insert(a);
    }
    int r = s.size();
    if(r == x) 
        return "Good";
    else if(r > x)
        return "Average";
    return "Bad";
}


int main()
{
    int t;
    vector<vector<int>> nums;
    vector<int> tmp;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n ;
        cin >> n;
        int x;
        cin >> x;
        int tp;
        for(int i = 0; i < n ; i ++)
        {
            cin >> tp;
            tmp.push_back(tp);
        }
        tmp.push_back(x);
        nums.push_back(tmp);
        tmp.clear();
    }
    for(vector<int> k : nums)
    {
        cout << sol(k) << endl;
    }
    return 0;
}