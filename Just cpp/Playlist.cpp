// #include <bits/stdc++.h>
// using namespace std;
// #define fast_io                       \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(0);
// #define endl "\n"
// #define ull unsigned long long
// #define pb push_back
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef pair<ll, bool> pllb;
// const ll MOD = 1000000007;
// const int N = (int)(1 * 1e6 + 10);
// const int MAXN = 2e5 + 5;

// void solve()
// {
//     ll n;
//     cin >> n;
//     ll a[n + 1] = {0};
//     for (ll i = 1; i < n + 1; i++)
//     {
//         cin >> a[i];
//     }
//     std::map<ll, ll> m;
//     ll i = 1, ans = 0;

//     for (ll j = 1; j < n + 1; j++)
//     {
//         i = std::max(i, m[a[j]] + 1);
//         ans = std::max(ans, j - i + 1);
//         m[a[j]] = j;
//     }
//     cout << ans << endl;
// }

// int32_t main()
// {
//     fast_io;

//     solve();

//     return 0;
// }

// DP SOLUTION
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n, ans, arr[N], dp[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", arr + i);
    unordered_map<int, int> m(1 << 12);
    for (int i = 1; i <= n; ++i)
    {
        if (!m.count(arr[i]))
            m[arr[i]] = -1;
        dp[i] = max(ans, min(dp[i - 1] + 1, i - m[arr[i]]));
        m[arr[i]] = i;
    }
    return printf("%d", *max_element(dp + 1, dp + n + 1)), 0;
}
