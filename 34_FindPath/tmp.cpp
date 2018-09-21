#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):
            val(x), left(nullptr), right(nullptr) { }
};

bool preTrave2(TreeNode *root, int k, vector<vector<int>> &res, vector<int> &vec) {
    if (root == nullptr && k == 0)
        return true;
    if (root == nullptr && k != 0)
        return false;
    if (root != nullptr && k == 0)
        return false;
    int val = root->val;
    vector<int> lvec, rvec;
    lvec.push_back(val);
    rvec.push_back(val);
    if (preTrave2(root->left, k-val, res, lvec))
    {
        res.push_back(lvec);
    }
    if (preTrave2(root->right, k-val, res, rvec))
    {
        res.push_back(rvec);
    }
    return !res.empty();
}

bool preTrave(TreeNode *root, int k, vector<vector<int>> &res) {
    vector<int> lvec, rvec;
    int val = root->val;
    preTrave2(root->left, k - val, res, lvec);
    preTrave2(root->right, k - val, res, rvec);
    return !res.empty();
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    if (root == nullptr || expectNumber == 0)
        return vector<vector<int>>();
    vector<vector<int>> res;
    bool ifFound = preTrave(root, expectNumber, res);
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}