#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):
            val(x), left(nullptr), right(nullptr) { }
};

void dfs_memoization(TreeNode *root, int num, int total, vector<vector<int>> &res, vector<int> &trace) {
    bool isLeaf = root && (root->left == nullptr) && (root->right == nullptr);
    if (isLeaf)
    {
        if (total + root->val == num)
            res.push_back(trace);
    } else
    {
        if (root->left)
            dfs_memoization(root->left, num, total + root->val, res, trace);
        if (root->right)
            dfs_memoization(root->right, num, total + root->val, res, trace);
    }
    trace.pop_back();
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    if (root == nullptr)
        return vector<vector<int>>();
    vector<vector<int>> res;
    vector<int> trace;
    dfs_memoization(root, expectNumber, expectNumber, res, trace);
    return res;
}

int main()
{
    return 0;
}
