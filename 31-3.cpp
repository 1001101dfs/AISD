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
vector<vector<ll>>g;
vector<bool>t;
void dfs(ll v) {
	t[v] = 1;
	for (auto& i : g[v]) {
		if (!t[i]) {
			dfs(i);
		}
	}
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	vector<vector<bool>>a(n + 2, vector<bool>(n + 2, false));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = 0;
	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < n; j++) {
			if (st[j] == '.')a[i + 1][j + 1] = true;
		}
	}
	ll x, y;
	cin >> x >> y;
	ll ans = 0;
	queue<pair<ll, ll>>q;
	q.push({ x, y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		if (a[x][y])ans++;
		a[x][y] = false;
		if (a[x + 1][y])q.push({ x + 1, y });
		if (a[x - 1][y])q.push({ x - 1, y });
		if (a[x][y + 1])q.push({ x, y + 1 });
		if (a[x][y - 1])q.push({ x, y - 1 });
		q.pop();
	}
	cout << ans;
}
