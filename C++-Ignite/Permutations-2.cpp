// The set of numbers has duplicates

#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void helper(vector<int> v, vector<vector<int>> &ans, int idx)
{
    if (idx == v.size())
    {
        ans.push_back(v);
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (i != idx && v[i] == v[idx])
        {
            continue;
        }
        std::swap(v[i], v[idx]);
        helper(v, ans, idx + 1);
    }
}

vector<vector<int>> permute(vector<int> &v)
{
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    helper(v, ans, 0);
    return ans;
}

int32_t main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    vector<vector<int>> res = permute(v);
    cout << endl;

    for (auto j : res)
    {
        for (auto i : j)

            cout << i << " ";
    }
    cout << "\n";
}
