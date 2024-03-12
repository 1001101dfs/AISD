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
class Tree {
private:
	vector<ll>g;
	ll n;
	void create(ll l, ll r, ll v, vector<ll>& a) {
		if (l == r) {
			g[v] = a[l];
			return;
		}
		ll mid = (l + r) >> 1;
		create(l, mid, v * 2 + 1, a);
		create(mid + 1, r, v * 2 + 2, a);
		g[v] = min(g[v * 2 + 1], g[v * 2 + 2]);
	}
	ll min_tree(ll l, ll r, ll left, ll right, ll v) {
		if (l == left && r == right) {
			return g[v];
		}
		ll mid = (l + r) >> 1;
		if (left <= mid && right > mid) {
			return min(min_tree(l, mid, left, min(right, mid), v * 2 + 1), min_tree(mid + 1, r, max(left, mid + 1), right, v * 2 + 2));
		}
		else {
			if (left <= mid) {
				return min_tree(l, mid, left, min(right, mid), v * 2 + 1);
			}
			if (right > mid) {
				return min_tree(mid + 1, r, max(left, mid + 1), right, v * 2 + 2);
			}
		}
	}
public:
	Tree(ll n) {
		this->n = n;
		g.resize(4 * n);
	}
	void build(vector<ll>& a) {
		create(0, n - 1, 0, a);
	}
	ll find(ll left, ll right) {
		return min_tree(0, n - 1, left, right, 0);
	}
};
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	vector <ll>a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	Tree b(n);
	b.build(a);
	for (int i = 0; i < n - m + 1; i++) {
		cout << b.find(i, i + m - 1) << endl;
	}
}
