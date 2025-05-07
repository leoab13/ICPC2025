#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> & v, int l, int h)
{
    int pivot = v[h];
    int i = (l - 1);
    for(int j = l; j <= h - 1 ; j++)
    {
        if(v[j] <= pivot)
        {
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[h]);
    return(i+1);
}

void quickSort(vector<int> & nums,int l, int h)
{
    if(l<h)
    {
        int pi = partition(nums,l,h);
        quickSort(nums, l, pi - 1);
        quickSort(nums, pi + 1, h);
    }
}

int sol(vector<int> values, int sum,int n)
{
    int i = 0;
    int acm = 0;
    while(acm <= sum - acm)
    {
        acm+=values[n - i++];
    }
    return i;
}

int main()
{
    vector<int> values;
    int n;
    int sum = 0;
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        sum += tmp;
        values.push_back(tmp);
    }
    quickSort(values,0,n - 1);
    cout << sol(values,sum, n - 1) << endl;
}