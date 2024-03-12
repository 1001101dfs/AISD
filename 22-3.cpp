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
	ll n, mx = 0;
	cin >> n;
	vector<ll>a(n), b(n, 0);
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] > a[i]) {
				b[j] = max(b[j], b[i] + 1);
				mx = max(mx, b[j]);
			}
		}
	}
	vector<ll>ans;
	for (int i = n - 1; i >= 0; i--) {
		if (b[i] == mx) {
			ans.push_back(a[i]);
			mx--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)cout << ans[i] << ' ';

}
