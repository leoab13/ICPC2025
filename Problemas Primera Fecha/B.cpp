#include <bits/stdc++.h>
using namespace std;


const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

long long solve(int n, int x, int y, int dir, vector<vector<bool>> &vis, vector<vector<int>> &a) {
	int cnt = 0;
	long long res = 0;
	long long mini = 0;
	long long prefix = 0;
	//cout << "New spiral" << endl;
	for(int i = 0; i < n * n; i++) {
		prefix += a[x][y];
		vis[x][y] = true;
		res = max(res, prefix - mini);
		mini = min(mini, prefix);
		//cout << x << " " << y << endl;
		if(i + 1 < n * n) {
			while(true) {
				int vx = x + dx[dir];
				int vy = y + dy[dir];
				//cout << vx << " " << vy << endl;
				if(vx >= 0 and vx < n and vy >= 0 and vy < n and not vis[vx][vy]) {
					break;
				}
				dir += 1;
				dir %= 4;
			}
		}
		x += dx[dir];
		y += dy[dir];
	}
	for(int i = 0; i < n; i++) fill(vis[i].begin(), vis[i].end(), false);
	return res;
}

int main() {
	cin.tie(0) -> sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<tuple<int, int, int>> starts = {
		{0, 0, 0},
		{0, 0, 1},
		{0, n - 1, 0},
		{0, n - 1, 3},
		{n - 1, 0, 1},
		{n - 1, 0, 2},
		{n - 1, n - 1, 2},
		{n - 1, n - 1, 3}
	};
	long long res = 0;
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	for(auto e : starts) {
		int x, y, dir;
		tie(x, y, dir) = e;
		long long cand = solve(n, x, y, dir, vis, a);
		if(res < cand) res = cand;
	}
	cout << res << endl;
	return 0;
}