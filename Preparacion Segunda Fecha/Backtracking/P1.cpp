/*
There are two bois and a gurl and three chairs, you have to get
all posible ways they can sit
print all permutations
*/
#include <bits/stdc++.h>
using namespace std;

void permute(vector<char>& arr, int l, int r) {
    if (l == r) {
        for (char c : arr)
            cout << c << " ";
        cout << endl;
        return;
    }

    for (int i = l; i <= r; ++i) {
        swap(arr[l], arr[i]);
        permute(arr, l + 1, r);
        swap(arr[l], arr[i]); // backtrack
    }
}

int main() {
    int x = 0;
    vector<char> k = {'b', 'b', 'g'};
    permute(k, 0, k.size() - 1);
    return 0;
}
