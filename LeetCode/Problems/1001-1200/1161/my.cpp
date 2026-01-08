#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Returns values in BFS (level-order)
    vector<int> bfsTraversal(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return res;
    }

    int maxLevelSum(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int level = 1, bestLevel = 1, bestSum = INT_MIN;
        while (!q.empty())
        {
            int sz = (int)q.size();
            int sum = 0;
            for (int i = 0; i < sz; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (sum > bestSum)
            {
                bestSum = sum;
                bestLevel = level;
            }
            ++level;
        }
        return bestLevel;
    }
};

int main()
{
    // Example usage:
    // TreeNode *root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    // Solution sol;
    // auto order = sol.bfsTraversal(root);
    // for (int v : order) cout << v << " ";
    return 0;
}