#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

vector<vector<int>> ans;

void permute(vector<int> &v, int idx)
{
    if (idx == v.size())
    {
        ans.push_back(v);
        return;
    }

    for (int i = idx; i < v.size(); i++)
    {
        std::swap(v[i], v[idx]);
        permute(v, idx + 1);
        std::swap(v[i], v[idx]);
    }
    return;
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
    // permute(v, 0);
    // DOING IT BY STL TRICK next_permutation
    sort(v.begin(), v.end());
    do
    {
        ans.push_back(v);
    } while (next_permutation(v.begin(), v.end()));

    for (auto j : ans)
    {
        for (auto i : j)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}