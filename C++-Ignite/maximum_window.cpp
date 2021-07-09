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

class Node
{
public:
    ll key;
    Node *left;
    Node *right;
    ll height;
};

ll height(Node *N)
{
    if (N == NULL)
    {
        return 0;
    }
    return N->height;
}

Node *newNode(ll key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *xr = x->right;

    x->right = y;
    y->left = xr;

    y->height = std::max(height(y->left), height(y->right) + 1);
    x->height = std::max(height(x->left), height(x->right) + 1);

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *yl = y->left;

    y->left = x;
    x->right = yl;

    x->height = std::max(height(x->left), height(x->right) + 1);
    y->height = std::max(height(y->left), height(y->right) + 1);

    return y;
}

int getBalance(Node *N)
{
    {
        if (N == NULL)
            return 0;
    }
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        return (newNode(key));
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *minValued(Node *node)
{
    Node *current = node;

    while (current->left)
    {
        current = current->left;
    }

    return current;
}

Node *deleteNode(Node *node, int key)
{
    if (node == NULL)
    {
        return node;
    }

    if (key < node->key)
    {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = deleteNode(node->right, key);
    }

    else
    {

        if ((node->left == NULL) ||
            (node->right == NULL))
        {
            Node *temp = node->left ? node->left : node->right;

            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;
            free(temp);
        }
        else
        {
            Node *temp = minValued(node->right);

            node->key = temp->key;

            node->right = deleteNode(node->right,
                                     temp->key);
        }
    }

    if (node == NULL)
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);
    if (balance > 1 &&
        getBalance(node->left) >= 0)
        return rightRotate(node);

    if (balance > 1 &&
        getBalance(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 &&
        getBalance(node->right) <= 0)
        return leftRotate(node);

    if (balance < -1 &&
        getBalance(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

ll findMax(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }

    ll res = root->key;
    ll lres = findMax(root->left);
    ll rres = findMax(root->right);
    if (lres > res)
    {
        res = lres;
    }
    if (rres > res)
    {
        res = rres;
    }

    return res;
}

void printMax(vector<ll> v, ll n, ll k)
{
    ll c = 0, l = 0;
    Node *root = NULL;

    for (ll i = 0; i < n; i++)
    {
        c++;
        root = insert(root, v[i]);

        if (c > k)
        {
            root = deleteNode(root, v[l++]);
            c--;
        }

        if (c == k)
        {
            cout << findMax(root) << " ";
        }
    }
}

int32_t main()
{

    ll n, k;
    cin >> n >> k;
    vector<ll> vec;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        vec.pb(x);
    }

    printMax(vec, n, k);
}
