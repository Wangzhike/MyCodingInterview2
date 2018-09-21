#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):
            val(x), left(nullptr), right(nullptr) { }
};

int TreeDepth(TreeNode* pRoot)
{
    if (pRoot == nullptr)
        return 0;
    queue<TreeNode*> que;
    que.push(pRoot);
    int len_level = 1;
    int len_next = 0;
    int heignt = 0;
    while (!que.empty())
    {
        auto node = que.front();
        que.pop();
        if (node->left)
        {
            que.push(node->left);
            ++len_next;
        }
        if (node->right)
        {
            que.push(node->right);
            ++len_next;
        }
        --len_level;
        if (len_level == 0)
        {
            ++heignt;
            len_level = len_next;
            len_next = 0;
        }
    }
    return heignt;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}