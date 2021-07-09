
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mod (int)(1e9 + 7)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define bloop(i, a, b) for (int i = a; i >= b; i--)
#define tc(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define int long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL)
#define in(x) scanf("%intd", &x)
#define rr return 0
#define prec(n) fixed << setprecision(n)
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int>>
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define pi pair<pair<int, int>, pair<int, int>>
#define fi first
#define se second
#define endl "\n"
const int MAXN = (int)((1e5) + 10);
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
bool isPrime(int N)
{
    for (int i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
int cbrt(int x)
{
    int lo = 1, hi = min(2000000ll, x);
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        if (mid * mid * mid < x)
        {
            lo = mid;
        }
        else
            hi = mid;
    }
    if (hi * hi * hi <= x)
        return hi;
    else
        return lo;
}
vector<int> m[5005];
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int nax = (int)(1 * 1e6 + 10);

// int SPF[N+5];

// void SOF()
// {
//     SPF[1] = 1;
//     for (int i=2; i<N; i++)
//         SPF[i] = i;
//     for (int i=4; i<N; i+=2)
//         SPF[i] = 2;

//     for (int i=3; i*i<N; i++)
//         {
//         if (SPF[i] == i)
//             {
//             for (int j=i*i; j<N; j+=i)
//                 if (SPF[j]==j)
//                    SPF[j] = i;
//             }
//         }
// }
int n;
int fen1[nax], fen2[nax];
int a[nax];
int maxi = -1;

void update1(int ind, int val)
{
    for (int i = ind; i <= maxi; i += i & -i)
        fen1[i] += val;
}

int sum1(int ind)
{
    int s = 0;
    for (int i = ind; i; i -= i & -i)
        s += fen1[i];

    return s;
}

void update2(int ind, int val)
{
    for (int i = ind; i <= maxi; i += i & -i)
        fen2[i] += val;
}

int sum2(int ind)
{
    int s = 0;
    for (int i = ind; i; i -= i & -i)
        s += fen2[i];

    return s;
}

signed main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
// for writing output to output.txt
// freopen("output.txt", "w", stdout);
#endif
    fio;
    int t = 1;
    // cin >> t;

    while (t--)
    {

        cin >> n;

        unordered_map<int, int> mpp1;

        int ind = 1;

        set<int> st;

        for0(i, n)
        {
            cin >> a[i];
            st.insert(a[i]);
        }

        while (st.size())
        {
            int el = *st.begin();
            mpp1[el] = ind++;
            st.erase(el);
        }

        for0(i, n)
            a[i] = mpp1[a[i]];

        maxi = ind + 1;

        for0(i, n)
            update2(a[i] + 1, 1);

        int cnt = 0;
        int ans = 0;
        unordered_map<int, int> mpp;

        for0(i, n)
        {
            update2(a[i] + 1, -1);
            int c1 = sum2(a[i]);

            int c2 = cnt - sum1(a[i]) - mpp[a[i]];

            //cout << sum1(a[i]) << endl;

            ans += c1 * c2;

            update1(a[i] + 1, 1);
            cnt++;
            mpp[a[i]]++;
        }

        cout << ans;
    }

    rr;
}