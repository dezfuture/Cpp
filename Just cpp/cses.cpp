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
    int n, x, y;
    cin >> n;
    vector<pair<int, pii>> v;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        v.pb({x, {-1, i}});
        v.pb({y, {1, i}});
    }
    std::sort(v.begin(), v.end());

    vector<int> rooms;
    int rooms_occ = 0, max_rooms = 0, in_or_out, index;
    int ans[MAXN];
    for (auto vec : v)
    {
        in_or_out = vec.second.first;
        index = vec.second.second;

        if (in_or_out == 1)
        {
            rooms.pb(ans[index]);
        }
        else if (rooms_occ == rooms.size())
        {
            ans[index] = ++max_rooms;
        }
        else
        {
            ans[index] = rooms[rooms_occ++];
        }
    }

    cout << max_rooms << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}

int32_t main()
{
    fast_io;

    solve();

    return 0;
}