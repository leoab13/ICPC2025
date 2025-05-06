/*#include <bits/stdc++.h>
using namespace std;

void sol(vector<vector<long>> & ords, vector<long> &ing, int &n, int&k)
{
    vector<long> sum(k,0);
    for(int i =0; i <k ; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum[i]+= ords[j][i];
        }
    }

    long md = INT64_MAX;
    for(int i =0; i < k; i++)
    {
        if(sum[i] != 0)
        {
            long d = ing[i]/sum[i];
            if(d < md)
            {
                md = d;
            }
        }
    }
    
    cout << (md + 1) << " ";

    for(int i =0; i <k; i++)
    {
        ing[i] = ing[i] - md * sum[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j =0; j < k;j++)
        {
            if(ing[j] >= ords[i][j])
            {
                ing[j] -=ords[i][j];
            }
            else
            {
                cout <<i +1 << endl;
                return;
            }
        }
    }
}

int main()
{
    int n,k;
    vector<long> ing;
    vector<vector<long>> ords;
    cin >>k;
    for(int i = 0 ; i < k; i++)
    {
        long tmp;
        cin >> tmp;
        ing.push_back(tmp);
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        vector<long> vtmp;
        for(int j = 0; j < k; j++)
        {
            long tmp;
            cin >> tmp;
            vtmp.push_back(tmp);
        }
        ords.push_back(vtmp);
    }
    sol(ords,ing,n,k);
    return 0;
}
    */
//https://codeforces.com/gym/105873/problem/D
#include <bits/stdc++.h>
using namespace std;

void solve(const vector<vector<long long>>& B, vector<long long>& A, int N, int K) {
    vector<long long> orderSum(K, 0);

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            orderSum[i] += B[j][i];
        }
    }

    long long minDay = numeric_limits<long long>::max();
    for (int i = 0; i < K; ++i) {
        if (orderSum[i] != 0) {
            long long day = A[i] / orderSum[i];
            minDay = min(minDay, day);
        }
    }

    cout << (minDay + 1) << " ";

    for (int i = 0; i < K; ++i) {
        A[i] -= minDay * orderSum[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (A[j] >= B[i][j]) {
                A[j] -= B[i][j];
            } else {
                cout << (i + 1) << endl;
                return;
            }
        }
    }
}

int main() {

    int K;
    cin >> K;
    vector<long long> A(K);
    for (int i = 0; i < K; ++i) {
        cin >> A[i];
    }

    int N;
    cin >> N;

    vector<vector<long long>> B(N, vector<long long>(K));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> B[i][j];
        }
    }

    solve(B, A, N, K);

    return 0;
}
