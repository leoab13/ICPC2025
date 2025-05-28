/*
There are two bois and a gurl and three chairs, you have to get
all posible ways they can sit
permutations without repeeting not using global SET
*/
#include <bits/stdc++.h>
using namespace std;

void permuteUnique(vector<char>& arr, int l, int r) {
    if (l == r) {
        for (char c : arr)
            cout << c << " ";
        cout << endl;
        return;
    }

    unordered_set<char> used;  // para este nivel de recursión

    for (int i = l; i <= r; ++i) {
        if (used.count(arr[i])) continue; // si ya usamos este carácter aquí, lo ignoramos

        used.insert(arr[i]);              // marcamos que este carácter ya se usó
        swap(arr[l], arr[i]);             // fijamos arr[i] en la posición l
        permuteUnique(arr, l + 1, r);     // permutamos el resto
        swap(arr[l], arr[i]);             // backtrack
    }
}

int main() {
    vector<char> k = {'b', 'b', 'g'};
    permuteUnique(k, 0, k.size() - 1);
    return 0;
}
