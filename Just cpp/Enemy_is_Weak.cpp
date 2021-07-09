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

int n;
int a[N], fen1[N], fen2[N];
int maximum = -1;

void update1(int index, int val)
{
    for (int i = 0; i <= maximum; i = i + (i & (-i)))
    {
        fen1[i] += val;
    }
}

void update2(int index, int val)
{
    for (int i = 0; i <= maximum; i = i + (i & (-i)))
    {
        fen2[i] += val;
    }
}

int sum1(int index)
{
    int s = 0;
    for (int i = index; i; i = i - (i & (-i)))
    {
        s += fen1[i];
    }
    return s;
}

int sum2(int index)
{
    int s = 0;
    for (int i = index; i; i = i - (i & (-i)))
    {
        s += fen2[i];
    }
    return s;
}

void solve()
{

    cin >> n;
    std::unordered_map<int, int> m;
    int index = 1;
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    while (s.size())
    {
        int ele = *s.begin();
        m[ele] = index++;
        s.erase(ele);
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = m[a[i]];
    }

    maximum = index + 1;

    for (int i = 0; i < n; i++)
    {
        update2(a[i] + 1, 1);
    }

    int count = 0, ans = 0;
    unordered_map<int, int> m1;

    for (int i = 0; i < n; i++)
    {
        update2(a[i] + 1, -1);
        int c1 = sum2(a[i]);
        int c2 = count - sum1(a[i]) - m1[a[i]];
        ans += c1 * c2;
        update1(a[i] + 1, 1);
        count++;
        m1[a[i]]++;
    }
    cout << ans << endl;
}

int32_t main()
{

    fast_io;

    solve();

    return 0;
}