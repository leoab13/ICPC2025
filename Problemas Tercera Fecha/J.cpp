#include <bits/stdc++.h>
using namespace std;

struct FenwickXor {
    int n;
    vector<unsigned long long> bit; 
    FenwickXor(int n=0): n(n), bit(n+1, 0ULL) {}
    void add(int idx, unsigned long long val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] ^= val;
    }
    unsigned long long pref(int idx) const {
        unsigned long long res = 0ULL;
        for (; idx > 0; idx -= idx & -idx) res ^= bit[idx];
        return res;
    }
    unsigned long long rangeXor(int l, int r) const {
        return pref(r) ^ pref(l-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<unsigned long long> a(N+1);
    FenwickXor fw(N);

    for (int i = 1; i <= N; ++i) {
        unsigned long long v; 
        cin >> v;
        a[i] = v;
        fw.add(i, v); 
    }

    string out;
    out.reserve(Q * 6);

    for (int qi = 0; qi < Q; ++qi) {
        char t; 
        cin >> t;
        if (t == 'P') {
            int l, r; 
            cin >> l >> r;
            unsigned long long xr = fw.rangeXor(l, r);
            if (xr == 0ULL) out += "JUAN\n";   
            else            out += "FRANK\n";  
        } else { // 'R'
            int k; long long x; 
            cin >> k >> x;
            long long nv_signed = (long long)a[k] + x;
            unsigned long long nv = (unsigned long long)nv_signed;
            unsigned long long delta = a[k] ^ nv;
            fw.add(k, delta);
            a[k] = nv;
        }
    }

    cout << out;
    return 0;
}
