#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define forn for (int i = 0; i < n; i++)
#define srt(v) sort(v.begin(), v.end());
#define rev(v) reverse(v.begin(), v.end());
#define kk '\n'
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> findSpiral(Node *root)
{
    vector<int> res;
    if (root == NULL)
    {
        return res;
    }

    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);
    Node *cur;

    while (!s1.empty() or !s2.empty())
    {
        while (!s1.empty())
        {
            cur = s1.top();
            res.push_back(cur->data);
            s1.pop();

            if (cur->right)
            {
                s2.push(cur->right);
            }
            if (cur->left)
            {
                s2.push(cur->left);
            }
        }

        while (!s2.empty())
        {
            cur = s2.top();
            res.push_back(cur->data);
            s2.pop();
            if (cur->left)
            {
                s1.push(cur->left);
            }

            if (cur->right)
            {
                s1.push(cur->right);
            }
        }
    }
    return res;
}
