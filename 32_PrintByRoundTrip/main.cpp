#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):
            val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int> > Print(TreeNode* pRoot) {
    if (pRoot == nullptr)
        return vector<vector<int>>();
    queue<TreeNode*> que;
    que.push(pRoot);
    int numOfCurLvl = 1;
    int numOfNextLvl = 0;
    vector<vector<int>> res;
    vector<int> level;
    int height = 0;
    while (!que.empty())
    {
        TreeNode *node = que.front();
        level.push_back(node->val);
        if (node->left)
        {
            que.push(node->left);
            ++numOfNextLvl;
        }
        if (node->right)
        {
            que.push(node->right);
            ++numOfNextLvl;
        }
        que.pop();
        --numOfCurLvl;
        if (numOfCurLvl == 0)
        {
            ++height;
            if (height & 0x1)
            {
                res.push_back(level);
            } else
            {
                res.push_back(vector<int>(level.rbegin(), level.rend()));
            }
            level.erase(level.begin(), level.end());
            numOfCurLvl = numOfNextLvl;
            numOfNextLvl = 0;
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}