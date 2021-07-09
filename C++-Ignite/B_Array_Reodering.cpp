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
const int MOD = 1000000007;
const int N = 1e3 + 2;
const int MAXN = 2e5 + 5;

void solve()
{

    ll n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.pb(a);
    }

    int count = 0;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a = __gcd(v[i], 2 * v[j]);
            if (a > 1)
            {
                count++;
            }
        }
    }

    cout << count << endl;
}

int32_t main()
{

    fast_io;

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}