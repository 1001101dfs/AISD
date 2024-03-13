#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <cctype>
#include <iterator>
#include <cmath>
 
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ld, ld> pdd;
 
const ll maxn = 1000009;
 
ll n, m, i, j, k;
vector<ll> p;
int f[maxn];
 
inline void test()
{
    f[1] = 1; f[2] = 2; f[3] = 3;
    for (ll i = 1; i <= 100; ++i)
        p.pb(i*i*i);
    cin >> n;
    for (ll i = 4; i <= n; ++i)
    {
        f[i] = 1000000009;
        for (ll j = 0; j<p.size(); ++j)
        {
            if (i >= p[j] && f[i] > f[i - p[j]] + 1)
                f[i] = f[i - p[j]] + 1;
        }
    }
    cout << f[n];
    //system("pause");
}
 
 
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    test();
    //system("pause");
    return 0;
}
