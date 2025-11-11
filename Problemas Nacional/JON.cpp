#include <bits/stdc++.h>
using namespace std;

struct AhoCorasick {
    struct Node {
        array<int, 26> next{};
        int link = -1;
        vector<int> out; // índices de patrones que terminan aquí
        Node() { next.fill(-1); }
    };

    vector<Node> trie;
    vector<int> scorePattern; // puntuación de cada patrón

    AhoCorasick() { trie.emplace_back(); }

    void addPattern(const string &s, int id, int scoreValue) {
        int v = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (trie[v].next[idx] == -1) {
                trie[v].next[idx] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[idx];
        }
        trie[v].out.push_back(id);
        if ((int)scorePattern.size() <= id) scorePattern.resize(id + 1);
        scorePattern[id] = scoreValue;
    }

    void build() {
        queue<int> q;
        trie[0].link = 0;
        for (int c = 0; c < 26; c++) {
            int u = trie[0].next[c];
            if (u != -1) {
                trie[u].link = 0;
                q.push(u);
            } else {
                trie[0].next[c] = 0;
            }
        }

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int c = 0; c < 26; c++) {
                int u = trie[v].next[c];
                if (u != -1) {
                    trie[u].link = trie[trie[v].link].next[c];
                    // heredar salidas
                    for (int id : trie[trie[u].link].out)
                        trie[u].out.push_back(id);
                    q.push(u);
                } else {
                    trie[v].next[c] = trie[trie[v].link].next[c];
                }
            }
        }
    }

    int search(const string &text) {
        int v = 0;
        int totalScore = 0;
        for (char ch : text) {
            if (ch < 'a' || ch > 'z') {
                v = 0; // ignorar caracteres no alfabéticos
                continue;
            }
            int c = ch - 'a';
            v = trie[v].next[c];
            for (int id : trie[v].out)
                totalScore += scorePattern[id];
        }
        return totalScore;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    AhoCorasick ac;
    ac.addPattern("ha", 0, 1);
    ac.addPattern("booooo", 1, -1);
    ac.addPattern("bravo", 2, 3);
    ac.build();

    cout << ac.search(s) << "\n";
    return 0;
}
/*
Casos de prueba:
1
INPUT
boooohaboooo

OUTPUT
-1

2
INPUT
brhavo
OUTPUT
1

3
INPUT
booo
OUTPUT
0

*/