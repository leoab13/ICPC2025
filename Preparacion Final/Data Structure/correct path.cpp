//https://leetcode.com/problems/simplify-path/description/
#include <bits/stdc++.h>
using namespace std;

void solution(string path)
{
    stack<string> st;
    string temp = "";
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == '/')
        {
            if (temp == "" || temp == ".")
            {
                temp = "";
                continue;
            }
            else if (temp == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else
            {
                st.push(temp);
            }
            temp = "";
        }
        else
        {
            temp += path[i];
        }
    }
    if (temp == "..")
    {
        if (!st.empty())
            st.pop();
    }
    else if (temp != "" && temp != ".")
    {
        st.push(temp);
    }
    string ans = "";
    while (!st.empty())
    {
        ans = "/" + st.top() + ans;
        st.pop();
    }
    if (ans == "")
        ans = "/";
    cout << ans << endl;
}

int main()
{
    string path;
    cin >> path;
    solution(path);
    return 0;
}