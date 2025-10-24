/*
Given an integer array arr[], Find all the subsets of the array.

A subset is any selection of elements from an array, where the order does not matter, and no element appears more than once.
 It can include any number of elements, from none (the empty subset) to all the elements of the array.
*/

#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> &arr)
{
vector<vector<int>> sol;
sol.push_back({});
  for(int v : arr)
  {
    int n = sol.size();
    for(int j = 0; j < n; j++)
    {
      vector<int> temp = sol[j];
      temp.push_back(v);
      sol.push_back(temp);
    }
  }
  for(auto v : sol)
  {
    for(auto x : v)
      cout << x << " ";
    cout << endl;
  }
}

int main()
{
vector<int> arr = {1,2,3};
solution(arr);
return 0;
}
//algorithm complexity O(n*2^n)
//space complexity O(2^n)