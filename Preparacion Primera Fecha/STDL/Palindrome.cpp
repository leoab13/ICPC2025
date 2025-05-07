//https://www.hackerearth.com/problem/algorithm/the-palindrome-2/
#include <bits/stdc++.h>
using namespace std;

bool palindrome(string & cad)
{
    int n = cad.size();
    char c1, c2;
    for(int i = 0; i < n/2; i++)
    {
        c1 = cad[i];
        c2 = cad[n - i - 1];
        if(!(c1 == c2))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<string> cads;
    for(int i = 0; i < n; i++)
    {
        string cad;
        cin >> cad;
        cads.push_back(cad);
    }
    for(string s : cads)
    {
        if(palindrome(s))
        {
            cout << "Yes"<< endl;
        }
        else{
            cout <<"No"<< endl;
        }
    }
    return 0;
}