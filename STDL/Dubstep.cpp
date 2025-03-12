//https://codeforces.com/problemset/problem/208/A
#include <bits/stdc++.h>
using namespace std;

void sol(string &cad) {
    stringstream ss;
    string palabra;
    bool primero = true;
    size_t pos = 0;
    while ((pos = cad.find("WUB")) != string::npos) {
        string sub = cad.substr(0, pos);
        if (!sub.empty()) {
            if (!primero) ss << " ";
            ss << sub;
            primero = false;
        }
        cad.erase(0, pos + 3);
    }
    
    if (!cad.empty()) {
        if (!primero) ss << " ";
        ss << cad;
    }
    
    cout << ss.str() << endl;
}

int main() {
    string cad;
    cin >> cad;
    sol(cad);
    return 0;
}
