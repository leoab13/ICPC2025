#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll int getX(vector<pair<ll int, ll int>> &k, ll int &minX,ll int &maxX)
{
    minX = k[0].first;
    maxX = k[0].first;
    for(auto c : k)
    {
        if(c.first < minX) minX = c.first;
        if(c.first > maxX) maxX = c.first;
    }

    return maxX - minX;
}

ll int getY(vector<pair<ll int, ll int>> &k, ll int &minY, ll int &maxY)
{
    minY = k[0].second;
    maxY = k[0].second;
    for(auto c : k)
    {
        if(c.second < minY) minY = c.second;
        if(c.second > maxY) maxY = c.second;
    }
    return maxY - minY;
}

ll int bestTwoKing(ll int w, ll int h, int k)
{
    vector<ll int> best;
    for(int i = 0; i < k + 1; i++)
    {
        best.push_back(((w+i) * (h+k-i)));
    }
    return *max_element(best.begin(),best.end());
}

ll int bestOneKing(ll int w, ll int h, ll int k,ll int &maxX, ll int &maxY, ll int &minX, ll int &minY,vector<pair<ll int, ll int>> &kings)
{
    vector<pair<int,int>> dxdy {{-k,-k},{-k,k},{k,-k},{k,k}};
    ll int nx,ny,wc,hc,option;
    ll int bestOne = w*h;
    int dx,dy;
    for(auto a : kings)
        {
            ll int x = a.first;
    ll int y = a.second;
    for(auto p : dxdy)
    {
        dx = p.first;
        dy = p.second;
        nx = x + dx;
        ny = y + dy;
        wc = max(maxX,nx) - min(minX, nx) + 1;
        hc = max(maxY,ny) - min(minY,ny) + 1;
        option = wc * hc;
        bestOne = max(bestOne,option);
    }
    }
    return bestOne;
}

void solution(vector<pair<ll int, ll int>> &kings, int &k)
{
    ll int minX,maxX,minY,maxY = 0;
    ll int w = getX(kings,minX,maxX);
    ll int h = getY(kings,minY,maxY);
    cout << max(bestTwoKing(w,h,k),bestOneKing(w,h,k,maxX,maxY,minX,minY,kings)) << "\n";
}

int main()
{
    ll n,k;
    cin >> n >> k;
    vector<pair<ll int, ll int>> kings;
    for(int i = 0 ; i < n; i++)
    {
        ll int t1,t2;
        cin >> t1>> t2;
        auto tmp = make_pair(t1,t2);
        kings.push_back(tmp);
    }
    if(n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    solution(kings,k);
    return 0;
}
