#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0);
#define endl "\n"
#define ull unsigned long long
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, bool> pllb;
const ll MOD = 1000000007;
const int N = (int)(1 * 1e6 + 10);
const int MAXN = 2e5 + 5;

void solve()
{
    ll x, n;
    cin >> x >> n;
    ll p[n];
    std::map<ll, ll> m;
    std::set<ll> s;

    s.insert(0);
    s.insert(x);
    m[x] = 1;

    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
        auto it = s.lower_bound(p[i]);
        ll a = *it;
        it--;
        ll b = *it;
        m[a - b]--;
        if (!m[a - b])
        {
            m.erase(a - b);
        }
        s.insert(p[i]);
        m[a - p[i]]++;
        m[p[i] - b]++;
        cout << ((--m.end())->first) << " ";
    }
}
int32_t main()
{
    fast_io;

    solve();

    return 0;
}



int minJumps(int a[], int n) {
    //O(n^2) solution
    int *jumps = new int[n];
    if(n == 0 || a[0] == 0) {
        return INT_MAX;
    }

    jumps[0] = 0;
    for (int i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (i <= j + a[j] && jumps[i] != INT_MAX) {
                jumps[i] = std::min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}