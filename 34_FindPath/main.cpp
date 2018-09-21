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

bool findPath(TreeNode *root, int num, vector<vector<int>> &res) {
    if (root == nullptr && num == 0)
        return true;
    if (root == nullptr && num != 0)
        return false;
    if (root != nullptr && num == 0)
        return false;
    if (root->left == nullptr && root->right == nullptr
        && root->val == num)
    {
        res.push_back(vector<int>{root->val});
        return true;
    }
    bool hasPath = false;
    int val = root->val;
    vector<int> lvec, rvec;
    if (findPath(root->left, num - val, res))
    {
        hasPath = true;
        /*for (int i = 0; i < res.size(); ++i)
            res[i].push_back(root->left->val);*/
    } else
    {
        for (int i = 0; i < res.size(); ++i)
            res[i].erase(res[i].begin(), res[i].end());
        res.erase(res.begin(), res.end());
    }
    int bg = res.size();
    if (findPath(root->right, num - val, res))
    {
        hasPath = true;
        /*for (int i = bg; i < res.size(); ++i)
            res[i].push_back(root->right->val);*/
    } else
    {
        for (int i = bg; i < res.size(); ++i)
            res[i].erase(res[i].begin(), res[i].end());
        res.erase(res.begin()+bg, res.end());
    }
    if (hasPath)
    {
        for (int i = 0; i < res.size(); ++i)
            res[i].push_back(val);
    } else {
        for (int i = 0; i < res.size(); ++i)
            res[i].erase(res[i].begin(), res[i].end());
        res.erase(res.begin(), res.end());
    }
    return hasPath;
}

static bool compare(vector<int> &lvec, vector<int> &rvec) {
    return lvec.size() > rvec.size();
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    if (root == nullptr || expectNumber == 0)
        return vector<vector<int>>();
    vector<vector<int>> tmp;
    vector<vector<int>> res;
    findPath(root, expectNumber, tmp);
    for (int i = 0; i < tmp.size(); ++i)
    {
        res.push_back(vector<int>(tmp[i].rbegin(), tmp[i].rend()));
    }
    std::sort(res.begin(), res.end(), compare);
    return res;
}


//int main()
//{
//
//}

