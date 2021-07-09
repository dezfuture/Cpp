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

// TRAPPING RAINWATER PROBLEM
// int rainWater(vector<int> v)
// {
//     std::stack<int> s;
//     int ans = 0;
//     for (int i = 0; i < v.size(); i++)
//     {
//         while (!s.empty() && v[s.top()] < v[i])
//         {
//             int curr = s.top();
//             s.pop();
//             if (s.empty())
//             {
//                 break;
//             }
//             int diff = i - s.top() - 1;
//             ans += (std::min(v[s.top()], v[i]) - v[curr]) * diff;
//         }
//         s.push(i);
//     }
//     return ans;
// }

//Maxlen substring with unique chracters
// string s;
// cin >> s;
// std::vector<int> v(256, -1);
// int maxlen = 0, start = -1;
// for (int i = 0; i < s.size(); i++)
// {
//     if (v[s[i]] > start)
//     {
//         start = v[s[i]];
//     }
//     v[s[i]] = i;
//     maxlen = std::max(maxlen, i - start);
// }
// cout << maxlen << endl;

// FLATTEN A BINARY TREE
// struct Node
// {
//     int data;
//     Node *left, *right;
//     Node(int val)
//     {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// void flatten(Node *root)
// {
//     if (root == NULL || (root->left == NULL && root->right == NULL))
//     {
//         return;
//     }

//     if (root->left != NULL)
//     {
//         flatten(root->left);

//         Node *temp = root->right;
//         root->right = root->left;
//         root->left = NULL;

//         Node *t = root->right;
//         while (t->right)
//         {
//             t = t->right;
//         }

//         t->right = temp;
//     }
//     flatten(root->right);
// }

// void Inorder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     Inorder(root->left);
//     cout << root->data << " ";
//     Inorder(root->right);
// }

void solve()
{
}

int32_t main()
{

    fast_io;

    solve();
}
