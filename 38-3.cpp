	#pragma GCC optimize("unroll-loops")
	#pragma GCC optimize("Ofast")
	#include <iostream>
	#include <cmath>
	#include <iomanip>
	#include <set>
	#include <algorithm>
	#include <fstream>
	#include <vector>
	#include <string>
	#include <climits>
	#include <ctime>
	#include <queue>
	#include <map>
	#include <stack>
	#include <unordered_set>
	#define ll long long
	#define f .first
	#define s .second
	#define mp make_pair
	#define pb push_back
	using namespace std;
	int main() {
		ll n, m;
		cin >> n >> m;
		vector<vector<ll>>a(n + 2, vector<ll>(m + 2, -1));
		set<pair<ll, ll>>pos;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
				if (a[i][j] == 1)a[i][j] = -1;
				else {
					if (a[i][j] == 2)pos.insert({ i, j });
					a[i][j] = LLONG_MAX;
				}
			
			}
		}
		queue<pair<ll, ll>>q;
		q.push({ 1, 1 });
		a[1][1] = 0;
		while (!q.empty()) {
			ll x = q.front().first;
			ll y = q.front().second;
			ll dx, dy;
			dx = x; dy = y;
			q.pop();
			while (a[x][y] != -1) {
				x++;
				if (pos.find({ x,y }) != pos.end()) {
					a[x][y] = min(a[x][y], a[dx][dy] + 1);
				}
			}
			x--;
			if (a[x][y] > a[dx][dy] + 1) {
				a[x][y] = a[dx][dy] + 1;
				q.push({ x,y });
			}
		
		
			x = dx; y = dy;
			while (a[x][y] != -1) {
				x--;
				if (pos.find({ x,y }) != pos.end()) {
					a[x][y] = min(a[x][y], a[dx][dy] + 1);
				}
			}
			x++;
			if (a[x][y] > a[dx][dy] + 1) {
				a[x][y] = a[dx][dy] + 1;
				q.push({ x,y });
			}

			x = dx; y = dy;
			while (a[x][y] != -1) {
				y++;
				if (pos.find({ x,y }) != pos.end()) {
					a[x][y] = min(a[x][y], a[dx][dy] + 1);
				}
			}
			y--;
			if (a[x][y] > a[dx][dy] + 1) {
				a[x][y] = a[dx][dy] + 1;
				q.push({ x,y });
			}

			x = dx; y = dy;
			while (a[x][y] != -1) {
				y--;
				if (pos.find({ x,y }) != pos.end()) {
					a[x][y] = min(a[x][y], a[dx][dy] + 1);
				}
			}
			y++;
			if (a[x][y] > a[dx][dy] + 1) {
				a[x][y] = a[dx][dy] + 1;
				q.push({ x,y });
			}
		}
		ll ans = LLONG_MAX;
		for (auto& i : pos) {
			ans = min(ans, a[i.first][i.second]);
		}
		cout << ans;
		return 0;
	}
