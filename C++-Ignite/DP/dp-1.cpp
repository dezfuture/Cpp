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
const int N = (int)(1 * 1e6 + 10);
const int MAXN = 2e5 + 5;

//Memoized
// int dp[N];

// int minsq(int n)
// {
//     if (n == 0 || n == 1 || n == 2 || n == 3)
//     {
//         return n;
//     }

//     if (dp[n] != MOD)
//     {
//         return dp[n];
//     }
//     for (int i = 1; i * i <= n; i++)
//     {
//         dp[n] = std::min(dp[n], 1 + minsq(n - i * i));
//     }

//     return dp[n];
// }

// dp

int minsq(int n)
{
    vector<int> dp(n + 1, MOD);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 1; i * i <= n; i++)
    {
        for (int j = 0; i * i + j <= n; j++)
        {
            dp[i * i + j] = min(dp[i * i + j], 1 + dp[j]);
        }
    }
    return dp[n];
}

void solve()
{
    // for (int i = 0; i < N; i++)
    // {
    //     dp[i] = MOD;
    // }

    int n;
    cin >> n;
    cout << minsq(n) << endl;
}

int32_t main()
{
    fast_io;

    solve();

    return 0;
}