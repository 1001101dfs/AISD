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
//#define s .second
#define mp make_pair
#define pb push_back
using namespace std;
int main() {
	struct Node {
		int x;
		int Height;
		Node(int x, int Height) : x(x), Height(Height) {};
	};
	int n, i, h;
	ll area, hPrev;
	stack<Node> s;
	scanf("%d", &n);
	ll res = 0;
	s.push(Node(0, -1));
	for (i = 1; i <= n + 1; i++) {
		if (i <= n) scanf("%d", &h); else h = 0;
		int x = i;
		while (h <= s.top().Height) {
			x = s.top().x; hPrev = s.top().Height; s.pop();
			area = 1LL * hPrev * (i - x);
			if (area > res) res = area;
		}
		s.push(Node(x, h));
	}
	printf("%lld\n", res);
}
