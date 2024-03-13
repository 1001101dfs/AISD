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
    ll n;
    double x, y, ans = 0;
    cin >> n;
    multiset<ll>a;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.insert(x);
    }
    while (a.size() != 1) {
        y = *a.begin();
        a.erase(a.find(y));
        x = *a.begin();
        a.erase(a.find(x));
        x += y;
        ans = ans + x / 20;
        a.insert(x);
    }
    cout << fixed << setprecision(2) <<  ans;
    return 0;
}
