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

vector<int> PrintFromTopToBottom(TreeNode* root) {
    if (root == nullptr)
        return vector<int>();
    queue<TreeNode*> que;
    que.push(root);
    vector<int> res;
    while (!que.empty())
    {
        TreeNode *node = que.front();
        cout << node->val << endl;
        res.push_back(node->val);
        que.pop();
        if (node->left)
            que.push(node->left);
        if (node->right)
            que.push(node->right);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}