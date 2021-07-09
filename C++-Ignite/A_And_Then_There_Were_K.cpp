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

void solve()
{
    ll n;
    cin >> n;
    ll ans;
    int s = n & (n - 1);
    if (s == 0)
    {
        cout << n - 1 << endl;
        return;
    }
    for (ll i = n - 2; i >= 0; i--)
    {
        s = s & i;
        if (s == 0)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

int32_t main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}