//https://codeforces.com/problemset/problem/651/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int,int> freq;
    int x, maxfreq = 0;
    for(int i=0; i<n; i++){
        cin >> x;
        maxfreq = max(maxfreq, ++freq[x]);
    }
    cout << min(n-1, n - maxfreq) << "\n";
    return 0;
}
