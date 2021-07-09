// COIN CHANEG PROBLEM

// Given a set of coins and a value V.Find the number of ways in which we can make change of V.

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

// MEMOIZATION
// int dp[N][N];

// int func(vector<int> &v, int n, int x)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     if (x < 0)
//     {
//         return 0;
//     }
//     if (n <= 0 && x > 0)
//     {
//         return 0;
//     }

//     if (dp[n][x] != -1)
//     {
//         return dp[n][x];
//     }

//     dp[n][x] = func(v, n - 1, x) + func(v, n, x - v[n - 1]);
//     return dp[n][x];
// }

// void solve()
// {
//     int n;
//     cin >> n;

//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             dp[i][j] = -1;
//         }
//     }

//     vector<int> v;
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         v.pb(a);
//     }
//     int x;
//     cin >> x;
//     cout << func(v, n, x) << endl;
// }

void solve()
{
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.pb(a);
    }

    int x;
    cin >> x;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < x + 1; j++)
        {
            if (j - v[i - 1] >= 0)
            {
                dp[i][j] += dp[i][j - v[i - 1]];
            }
            dp[i][j] += dp[i - 1][j];
        }
    }
    int n1 = dp[n][x];

    cout << n1 << endl;
}

signed main()
{

    fast_io;

    solve();

    return 0;
}