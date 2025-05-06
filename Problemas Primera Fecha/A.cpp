//https://codeforces.com/gym/105873/problem/A
#include <bits/stdc++.h>
using namespace std;

bool isHealthy(string S, string P) {
    size_t pos;
    while ((pos = P.find(S)) != string::npos) {
        P.replace(pos, S.length(), "");
    }
    return P.empty();
}

int main() {
    string S;
    int N;
    cin >> S >> N;
    while (N--) {
        string P;
        cin >> P;
        cout << (isHealthy(S, P) ? "Yes" : "No") << endl;
    }
    return 0;
}
