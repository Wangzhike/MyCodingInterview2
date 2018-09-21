#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):
            val(x), left(nullptr), right(nullptr) {}
};

bool isSubTree(TreeNode *p, TreeNode *q) {
    if (q == nullptr)
        return true;
    if (p == nullptr)
        return false;
    if (p->val == q->val)
    {
        return isSubTree(p->left, q->left) && isSubTree(p->right, q->right);
    }
    return false;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if (pRoot2 == nullptr)
        return false;
    if (pRoot1 == nullptr)
        return false;
    if (pRoot1->val == pRoot2->val)
    {
        bool isSub = isSubTree(pRoot1, pRoot2);
        if (isSub)
            return true;
    }
    return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}