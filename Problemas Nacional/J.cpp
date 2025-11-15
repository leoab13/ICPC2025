#include<bits/stdc++.h>
using namespace std;

int countOcc(string &s,string &sb)
{
    int count = 0;
    size_t pos = s.find(sb,0);
    while(pos!=string::npos)
    {
        count++;
        pos=s.find(sb,pos+1);
    }
    return count;
}

int main()
{
    string a = "ha";
    string b = "boooo";
    string c = "bravo"; 
    string s;
    cin >> s;
    int ans = 0;
    ans+= countOcc(s,a);
    ans-= countOcc(s,b);
    ans+= countOcc(s,c) * 3;
    cout << ans << endl;
    return 0;
}