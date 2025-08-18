//arboles[0,4,5]
//[150,160,708]
#include<bits/stdc++.h>
using namespace std;


void solution(vector<int> &v, int&n)
{
    vector<int> trees;
    vector<int> h;
    for(int i = 0; i < n; i++)
    {
        if(v[i] < 0)
        {
            trees.push_back(i);
        }
        else{
            h.push_back(v[i]);
        }
    }

    sort(h.begin(),h.end());


    int c = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] == -1)
        {
            cout << -1 << " ";
        }
        else{
            cout << h[c++] << " ";
        }
    }


}
/*
public static void main(String ars[])
{
    
}
*/

int main()
{
    
    vector<int> v = {-1, 150, 190, 170, -1, -1, 160, 180};//arreglo
    int n = v.size(); // size of the array
    solution(v,n);
    return 0;
}