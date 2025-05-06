//https://codeforces.com/problemset/problem/405/A
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


int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    for(int i = 0 ; i  < n ; i++)
    {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    quickSort(nums,0,n-1);
    for(auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}