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

bool isPalindrome(char string1[])
{
    int i, length;
    int flag = 0;

    length = strlen(string1);

    for (i = 0; i < length; i++)
    {
        if (string1[i] != string1[length - i - 1])
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void solve(int a)
{
    int n, k;
    cin >> n >> k;
    char s[n];
    cin >> s;

    string alpha = "abcdefghijklmnopqrstuvwxyz";
    int ans = 0;
    string str;
    for (int i = 0; i < k; i++)
    {
        str[i] = alpha[i];
    }

    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        for (int len = 1; len <= n - i; len++)
        {
            v.pb(str.substr(i, len));
        }
    }

    int len = v.size();
    for (int i = 0; i < len; i++)
    {
        char s1[n];
        if (v[i].size() == n)
        {
            while (n--)
            {
                int j = 0;
                s1[j] = v[i][j];
                if (isPalindrome(s1))
                {
                    ans++;
                }
            }
        }
    }

    cout << "Case #" << a << ": " << ans << endl;
}

int32_t main()
{

    fast_io;

    ll t;
    cin >> t;

    for (int a = 1; a <= t; a++)
    {
        solve(a);
    }
    return 0;
}